/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  A placeable object in a The Witcher area.
 */

#include <memory>

#include "src/common/util.h"

#include "src/aurora/gff3file.h"

#include "src/graphics/aurora/model.h"

#include "src/engines/aurora/util.h"

#include "src/engines/witcher/placeable.h"

namespace Engines {

namespace Witcher {

Placeable::Placeable(const Aurora::GFF3Struct &placeable) : Situated(kObjectTypePlaceable),
	_state(kStateDefault), _hasInventory(false) {

	load(placeable);
}

Placeable::~Placeable() {
}

void Placeable::load(const Aurora::GFF3Struct &placeable) {
	Common::UString temp = placeable.getString("TemplateResRef");

	std::unique_ptr<Aurora::GFF3File> utp;
	if (!temp.empty())
		utp.reset(loadOptionalGFF3(temp, Aurora::kFileTypeUTP, MKTAG('U', 'T', 'P', ' ')));

	Situated::load(placeable, utp ? &utp->getTopLevel() : 0);
}

void Placeable::setModelState() {
	if (!_model)
		return;

	switch (_state) {
		case kStateDefault:
			_model->setState("default");
			break;

		case kStateOpen:
			_model->setState("open");
			break;

		case kStateClosed:
			_model->setState("close");
			break;

		case kStateDestroyed:
			_model->setState("dead");
			break;

		case kStateActivated:
			_model->setState("on");
			break;

		case kStateDeactivated:
			_model->setState("off");
			break;

		default:
			_model->setState("");
			break;
	}

}

void Placeable::show() {
	setModelState();

	Situated::show();
}

void Placeable::hide() {
	leave();

	Situated::hide();
}

void Placeable::loadObject(const Aurora::GFF3Struct &gff) {
	// State

	_state = (State) gff.getUint("AnimationState", (uint) _state);

	_hasInventory = gff.getBool("HasInventory", _hasInventory);
}

void Placeable::enter() {
	highlight(true);
}

void Placeable::leave() {
	highlight(false);
}

void Placeable::highlight(bool enabled) {
	if (_model)
		_model->drawBound(enabled);
}

bool Placeable::isOpen() const {
	return _state == kStateOpen;
}

bool Placeable::isActivated() const {
	return isOpen();
}

bool Placeable::click(Object *triggerer) {
	// If the placeable is locked, just play the appropriate sound and bail
	if (isLocked()) {
		playSound(_soundLocked);
		return false;
	}

	// If the object was destroyed, nothing more can be done with it
	if (_state == kStateDestroyed)
		return true;

	_lastUsedBy = triggerer;

	// Objects with an inventory toggle between open and closed
	if (_hasInventory) {
		if (isOpen())
			return close(triggerer);

		return open(triggerer);
	}

	// Objects without an inventory toggle between activated and deactivated
	if (isActivated())
		return deactivate(triggerer);

	return activate(triggerer);
}

bool Placeable::open(Object *opener) {
	if (!_hasInventory)
		return false;

	if (isOpen())
		return true;

	if (isLocked()) {
		playSound(_soundLocked);
		return false;
	}

	_lastOpenedBy = opener;

	playSound(_soundOpened);
	runScript(kScriptOpen, this, opener);

	_state = kStateOpen;

	return true;
}

bool Placeable::close(Object *closer) {
	if (!_hasInventory)
		return false;

	if (!isOpen())
		return true;

	_lastClosedBy = closer;

	playSound(_soundClosed);
	runScript(kScriptClosed, this, closer);

	_state = kStateClosed;

	return true;
}

bool Placeable::activate(Object *user) {
	if (_hasInventory)
		return false;

	if (isActivated())
		return true;

	if (isLocked()) {
		playSound(_soundLocked);
		return false;
	}

	playSound(_soundUsed);
	runScript(kScriptUsed, this, user);

	_state = kStateActivated;

	return true;
}

bool Placeable::deactivate(Object *user) {
	if (_hasInventory)
		return false;

	if (!isActivated())
		return true;

	if (isLocked()) {
		playSound(_soundLocked);
		return false;
	}

	playSound(_soundUsed);
	runScript(kScriptUsed, this, user);

	_state = kStateDeactivated;

	return true;
}

} // End of namespace Witcher

} // End of namespace Engines
