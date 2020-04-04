/*
   Copyright 2006-2020 The QElectroTech Team
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
#ifndef ELEMENTQUERYWIDGET_H
#define ELEMENTQUERYWIDGET_H

#include <QWidget>
#include <QButtonGroup>

class QListWidgetItem;

namespace Ui {
class ElementQueryWidget;
}

/**
 * @brief The ElementQueryWidget class
 * A widget use to edit a sql query for get element information
 * This widget only work to get information from ProjectDataBase
 */
class ElementQueryWidget : public QWidget
{
    Q_OBJECT

	public:
		explicit ElementQueryWidget(QWidget *parent = nullptr);
		~ElementQueryWidget();

		QString queryStr() const;

	private slots:
		void on_m_up_pb_clicked();
		void on_m_add_pb_clicked();
		void on_m_remove_pb_clicked();
		void on_m_down_pb_clicked();
		void on_m_edit_sql_query_cb_clicked();

		void updateQueryLine();
		QStringList selectedKeys() const;
		void setUpItems();

	private:
		Ui::ElementQueryWidget *ui;
		QHash <QString, QString> m_export_info;
		QButtonGroup m_button_group;
		QList <QListWidgetItem *> m_items_list;
		QString m_custom_query;
};

#endif // ELEMENTQUERYWIDGET_H