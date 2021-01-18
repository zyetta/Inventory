#ifndef DATABASEMAIN_H_INCLUDED
#define DATABASEMAIN_H_INCLUDED

void CreateDatabase(sqlite3 *db, const char* filename);
static int callback(void *NotUsed, int argc, char **argv, char **szColName);

#endif // DATABASEMAIN_H_INCLUDED
