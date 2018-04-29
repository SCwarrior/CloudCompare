#ifndef CCAPPLICATION_H
#define CCAPPLICATION_H

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
//#          COPYRIGHT: CloudCompare project                               #
//#                                                                        #
//##########################################################################

#include <QApplication>


//! Mimic Qt's qApp for easy access to the application instance
#define ccApp (static_cast<ccApplication *>( QCoreApplication::instance() ))

class ccApplication : public QApplication
{
public:
	//! This must be called before instantiating the application class so it
	//! can setup OpenGL first.
	static void	init();
	
	ccApplication( int &argc, char **argv );
	
	QString versionStr() const;
	QString versionLongStr( bool includeOS ) const;
	
#ifdef Q_OS_MAC
protected:
	bool event( QEvent *inEvent );
#endif
	
private:
	static QString s_version;
};

#endif
