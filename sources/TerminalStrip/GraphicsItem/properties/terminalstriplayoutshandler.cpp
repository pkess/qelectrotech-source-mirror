/*
	Copyright 2006-2024 The QElectroTech Team
	This file is part of QElectroTech.
	
	QElectroTech is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.
	
	QElectroTech is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with QElectroTech.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "terminalstriplayoutshandler.h"

#include <QObject>

TerminalStripLayoutsHandler::TerminalStripLayoutsHandler()
{

	m_default_layout = QSharedPointer<TerminalStripLayoutPattern>::create();
	m_default_layout->m_name = QObject::tr("Disposition par défaut");
}

QSharedPointer<TerminalStripLayoutPattern> TerminalStripLayoutsHandler::defaultLayout()
{
	return m_default_layout;
}
