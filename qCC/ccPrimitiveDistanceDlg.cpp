//##########################################################################
//#                                                                        #
//#                              CLOUDCOMPARE                              #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 or later of the License.      #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: Chris Brown                                        #
//#                                                                        #
//##########################################################################

#include "ccPrimitiveDistanceDlg.h"

//Qt
#include <QHeaderView>
#include <QMessageBox>


//System
#include <assert.h>

static bool s_signedDist = true;
static bool s_flipNormals = false;
ccPrimitiveDistanceDlg::ccPrimitiveDistanceDlg(QWidget* parent)
	: QDialog(parent, Qt::Tool)
	, Ui::primitiveDistanceDlg()
{
	setupUi(this);

	

	signedDistCheckBox->setChecked(s_signedDist);
	flipNormalsCheckBox->setEnabled(s_signedDist);
	flipNormalsCheckBox->setChecked(s_flipNormals);
	
	connect(cancelButton, &QPushButton::clicked, this, &ccPrimitiveDistanceDlg::cancelAndExit);
	connect(okButton, &QPushButton::clicked, this, &ccPrimitiveDistanceDlg::applyAndExit);
	connect(signedDistCheckBox, &QCheckBox::toggled, this, &ccPrimitiveDistanceDlg::toggleSigned);
}

ccPrimitiveDistanceDlg::~ccPrimitiveDistanceDlg()
{
}

void ccPrimitiveDistanceDlg::applyAndExit()
{
	s_signedDist = signedDistances();
	s_flipNormals = flipNormals();
	accept();
}

void ccPrimitiveDistanceDlg::cancelAndExit()
{
	reject();
}

void ccPrimitiveDistanceDlg::toggleSigned(bool state)
{
	flipNormalsCheckBox->setEnabled(state);
}

