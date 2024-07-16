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
#ifndef TERMINALSTRIPPROJECTCONFIGPAGE_H
#define TERMINALSTRIPPROJECTCONFIGPAGE_H

#include "../../../ui/configpage/projectconfigpages.h"

class TerminalStripLayoutEditor;

class TerminalStripProjectConfigPage : public ProjectConfigPage
{
		Q_OBJECT
	public:
		TerminalStripProjectConfigPage(QETProject *project, QWidget *parent = nullptr);

		QString title() const override;
		QIcon icon() const override;

		void applyProjectConf() override {}

	protected:
		void initWidgets() override;
		void initLayout() override{}
		void readValuesFromProject() override {}
		void adjustReadOnly() override {}

	private:
		TerminalStripLayoutEditor *m_layout_editor { nullptr };
};

#endif // TERMINALSTRIPPROJECTCONFIGPAGE_H
