/*
 *  Copyright (C) 2010 Andriy Rysin (rysin@kde.org)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


#ifndef LAYOUT_WIDGET_H_
#define LAYOUT_WIDGET_H_

#include <QVariant>
#include <QWidget>

#include "flags.h"
#include "x11_helper.h"

class QPushButton;
class KeyboardConfig;
class LayoutsMenu;
class XEventNotifier;

/**
 * Note: does not listen to configuration changes as currently we only use it in screen lock dialog
 */
class LayoutWidget : public QWidget
{
	Q_OBJECT

public:
	explicit LayoutWidget(QWidget* parent = 0, const QList<QVariant>& args = QList<QVariant>());
	virtual ~LayoutWidget();

private Q_SLOTS:
	void toggleLayout();
    void layoutChanged();
    //    void configChanged();

private:
	void init();
	void destroy();

	XEventNotifier* xEventNotifier;
	QPushButton* widget;
	KeyboardConfig* keyboardConfig;
	Flags* flags;
};

#endif /* LAYOUT_WIDGET_H_ */
