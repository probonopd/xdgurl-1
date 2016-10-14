#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

#include "json.h"

namespace Utility {

Json::Json(QObject *parent) : QObject(parent)
{}

bool Json::isValid(const QString &json)
{
    QJsonParseError jsonError;
    QJsonDocument::fromJson(json.toUtf8(), &jsonError);
    if (jsonError.error == QJsonParseError::NoError) {
        return true;
    }
    return false;
}

QJsonObject Json::convertStrToObj(const QString &json)
{
    QJsonObject jsonObj;
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(json.toUtf8(), &jsonError);
    if (jsonError.error == QJsonParseError::NoError && jsonDoc.isObject()) {
        jsonObj = jsonDoc.object();
    }
    return jsonObj;
}

QString Json::convertObjToStr(const QJsonObject &jsonObj)
{
    QJsonDocument jsonDoc(jsonObj);
    return QString::fromUtf8(jsonDoc.toJson());
}

} // namespace Utility