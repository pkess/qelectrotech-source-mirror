/*
	Copyright 2006-2022 The QElectroTech Team
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
#ifndef REPLACEQGRAPHICSITEMCOMMAND_H
#define REPLACEQGRAPHICSITEMCOMMAND_H

#include "../diagramcontent.h"

#include <QUndoCommand>

class Diagram;

class ReplaceQGraphicsItemCommand : public QUndoCommand
{
	public:
		ReplaceQGraphicsItemCommand(Diagram *diagram, const DiagramContent &content, QUndoCommand * parent = nullptr);
		~ReplaceQGraphicsItemCommand() override;

	private:
		ReplaceQGraphicsItemCommand(const ReplaceQGraphicsItemCommand &);

	public:
		void undo() override;
		void redo() override;

		// attributes
	private:
                Diagram *m_diagram;
};

#endif // REPLACEQGRAPHICSITEMCOMMAND_H
