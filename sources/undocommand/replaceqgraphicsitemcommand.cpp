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
#include "replaceqgraphicsitemcommand.h"

#include "../diagram.h"


/**
	@brief ReplaceQGraphicsItemCommand::ReplaceQGraphicsItemCommand
	@param diagram : deigram where this undo work
	@param content : content to remove
	@param parent : parent undo
*/
ReplaceQGraphicsItemCommand::ReplaceQGraphicsItemCommand(
		Diagram *diagram,
		const DiagramContent &content,
		QUndoCommand *parent) :
        QUndoCommand(parent),
        //m_replaced_contents(content),
        m_diagram(diagram)
{
    setText(QString(QObject::tr(
                            "replace %1",
							"undo caption - %1 is a sentence listing the replaced content"))
            .arg(content.sentence(DiagramContent::All)));
}

ReplaceQGraphicsItemCommand::~ReplaceQGraphicsItemCommand()
{
}

/**
	@brief ReplaceQGraphicsItemCommand::undo
	Undo this command
*/
void ReplaceQGraphicsItemCommand::undo()
{
	QUndoCommand::undo();
}

/**
	@brief ReplaceQGraphicsItemCommand::redo
	Redo the delete command
*/
void ReplaceQGraphicsItemCommand::redo()
{
	QUndoCommand::redo();
}
