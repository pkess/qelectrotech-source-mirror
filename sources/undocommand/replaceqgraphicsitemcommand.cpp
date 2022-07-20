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
#include "addgraphicsobjectcommand.h"
#include "../qetdiagrameditor.h"
#include "../qetgraphicsitem/ViewItem/qetgraphicstableitem.h"
#include "../qetgraphicsitem/conductor.h"
#include "../qetgraphicsitem/conductortextitem.h"
#include "../qetgraphicsitem/dynamicelementtextitem.h"
#include "../qetgraphicsitem/element.h"
#include "../qetgraphicsitem/elementtextitemgroup.h"
#include "../qetgraphicsitem/terminal.h"
#include "addelementtextcommand.h"

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
                            "undo caption - %1 is a sentence listing the removed content"))
            .arg(content.sentence(DiagramContent::All)));
}

ReplaceQGraphicsItemCommand::~ReplaceQGraphicsItemCommand()
{
        //m_diagram->qgiManager().release(m_replaced_contents.items(DiagramContent::All));
}

/**
	@brief ReplaceQGraphicsItemCommand::undo
	Undo this command
*/
void ReplaceQGraphicsItemCommand::undo()
{
//	m_diagram->showMe();
/*
	for(QGraphicsItem *item : m_removed_contents.items())
		m_diagram->addItem(item);

		//We relink element after every element was added to diagram
	for(Element *e : m_removed_contents.m_elements)
		for(Element *elmt : m_link_hash[e])
				e->linkToElement(elmt);

	for(DynamicElementTextItem *deti : m_removed_contents.m_element_texts)
	{
		if(m_elmt_text_hash.keys().contains(deti))
			m_elmt_text_hash.value(deti)->addDynamicTextItem(deti);
		else if (m_grp_texts_hash.keys().contains(deti))
		{
			Element *elmt = m_grp_texts_hash.value(deti)->parentElement();
			elmt->addDynamicTextItem(deti);
			elmt->addTextToGroup(deti, m_grp_texts_hash.value(deti));
		}
	}

	for (auto table : m_table_scene_hash.keys())
	{
		if (!m_table_scene_hash.value(table).isNull()) {
			m_table_scene_hash.value(table)->addItem(table);
		}
	}
*/
	QUndoCommand::undo();
}

/**
	@brief ReplaceQGraphicsItemCommand::redo
	Redo the delete command
*/
void ReplaceQGraphicsItemCommand::redo()
{
//	m_diagram -> showMe();
/*
	for(Conductor *c : m_removed_contents.conductors(DiagramContent::AnyConductor))
	{
			//If option one text per folio is enable, and the text item of
			//current conductor is visible (that mean the conductor have the single displayed text)
			//We call adjustTextItemPosition to other conductor at the same potential to keep
			//a visible text on this potential.
		if (m_diagram -> defaultConductorProperties.m_one_text_per_folio && c -> textItem() -> isVisible())
		{
			QList <Conductor *> conductor_list;
			conductor_list << c -> relatedPotentialConductors(false).values();
			if (conductor_list.count())
				conductor_list.first() -> calculateTextItemPosition();
		}
	}

	for(Element *e : m_removed_contents.m_elements)
	{
			//Get linked element, for relink it at undo
		if (!e->linkedElements().isEmpty())
			m_link_hash.insert(e, e->linkedElements());
	}

	for(DynamicElementTextItem *deti : m_removed_contents.m_element_texts)
	{
		if(deti->parentGroup() && deti->parentGroup()->parentElement())
			deti->parentGroup()->parentElement()->removeTextFromGroup(deti, deti->parentGroup());

		deti->parentElement()->removeDynamicTextItem(deti);
		deti->setParentItem(nullptr);
	}

	for (auto table : m_table_scene_hash.keys())
	{
		if (!m_table_scene_hash.value(table).isNull()) {
			m_table_scene_hash.value(table)->removeItem(table);
		}
	}

	for(QGraphicsItem *item : m_removed_contents.items())
		m_diagram->removeItem(item);
*/
	QUndoCommand::redo();
}
