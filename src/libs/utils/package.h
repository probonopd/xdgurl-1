#ifndef UTILS_PACKAGE_H
#define UTILS_PACKAGE_H

#include <QObject>

namespace utils {

class Package : public QObject
{
    Q_OBJECT

public:
    explicit Package(QObject *parent = 0);

    static bool installProgram(const QString &path, const QString &targetPath);
    static bool installFile(const QString &path, const QString &targetPath);
    static bool installPlasmapkg(const QString &path, const QString &type = "plasmoid");
    static bool uninstallPlasmapkg(const QString &path, const QString &type = "plasmoid");
    static bool uncompressArchive(const QString &path, const QString &targetDir);

private:
    static bool execute(const QString &program, const QStringList &arguments);
};

} // namespace utils

#endif // UTILS_PACKAGE_H