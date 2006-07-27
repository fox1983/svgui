/* -*- c-basic-offset: 4 indent-tabs-mode: nil -*-  vi:set ts=8 sts=4 sw=4: */

/*
    Sonic Visualiser
    An audio file viewer and annotation editor.
    Centre for Digital Music, Queen Mary, University of London.
    
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.  See the file
    COPYING included with this distribution for more information.
*/

#ifndef _LIST_INPUT_DIALOG_H_
#define _LIST_INPUT_DIALOG_H_

#include <QDialog>
#include <QString>
#include <QStringList>

#include <vector>

class QRadioButton;

/**
 * Like QInputDialog::getItem(), except that it offers the items as a
 * set of radio buttons instead of in a single combo box.
 */

class ListInputDialog : public QDialog
{
public:
    virtual ~ListInputDialog();

    static QString getItem(QWidget *parent, const QString &title,
                           const QString &label, const QStringList &list,
                           int current = 0, bool *ok = 0, Qt::WFlags f = 0);

protected:
    ListInputDialog(QWidget *parent, const QString &title,
                    const QString &label, const QStringList &list,
                    int current = 0, Qt::WFlags f = 0);

    QString getCurrentString() const;
    
    QStringList m_strings;
    std::vector<QRadioButton *> m_radioButtons;
};

#endif
