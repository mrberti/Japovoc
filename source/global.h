#ifndef GLOBAL_H
#define GLOBAL_H

/**
  This file contains some makro definitions and global variables
  */

/// Makro for creating settings. The path should be the direktory of the binary
#define SETTINGS_CREATE	QSettings settings("settings.ini", QSettings::IniFormat)

#endif // GLOBAL_H
