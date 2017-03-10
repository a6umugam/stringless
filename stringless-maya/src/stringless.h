/*
 * Copyright Justin Tennant <justin.tennant@sjsu.edu> 2017.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */

/* 
 * File:   stringless.h
 * Author: Justin Tennant <justin.tennant@sjsu.edu>
 *
 * Created on March 6, 2017, 12:42 AM
 */

#ifndef STRINGLESS_H
#define STRINGLESS_H

#include <QtCore/QPointer>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>

#include <maya/MPxCommand.h>

class StringlessDialog : public QWidget {
    Q_OBJECT
    public:
        StringlessDialog(QWidget* parent = 0);

        
    signals:
        void dialogDismissed();
        void objectCreated(const QString& objectName);
    public slots:
        void accept();
        //void fieldChanged(const QString& newValue);
        //void sliderChanged(int newValue);
            
    private:
        QDialogButtonBox    *fButtonBox;
        double              fcurValue;
        QLineEdit           *fField;
        QPointer<QWidget>   fForm;
        QSlider             *fSlider;
};

class Stringless : public MPxCommand
{
public:
	static void		cleanup();
	static void*            creator()	{ return new Stringless(); }

	MStatus			doIt(const MArgList& args);

	static QPointer<StringlessDialog>    	stringlessWindow;
	static const MString			commandName;
};

#endif /* STRINGLESS_H */

