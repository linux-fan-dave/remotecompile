#ifndef REMOTECOMPILER_H
#define REMOTECOMPILER_H

#include <QObject>

namespace RemoteCompile {

class RemoteCompiler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit RemoteCompiler(QObject *parent = nullptr);
    virtual ~RemoteCompiler() = default;

    QString name() const;
    void setName(const QString &name);

Q_SIGNALS:
    void nameChanged();

public Q_SLOTS:
private:
    QString m_name;
};

}
#endif // REMOTECOMPILER_H
