#include <QCoreApplication>

#include <QMap>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QMap<int, QList<int>> dataMap;

    dataMap[16] = QList<int>() << 10 << 20 << 30;
    dataMap[4] = QList<int>() << 40 << 50 << 60;

    QString sqlInsert = "INSERT INTO tabela (id, valor) VALUES ";

    QMapIterator<int, QList<int>> it(dataMap);
    while (it.hasNext()) {
        it.next();
        int chave = it.key();
        QList<int> valores = it.value();

        for (int i = 0; i < valores.size(); ++i) {
            int valor = valores[i];
            sqlInsert += QString("(%1, %2), ").arg(chave).arg(valor);
        }
    }

    sqlInsert.chop(2);
    sqlInsert.append(";");

    qInfo() << sqlInsert;

    return a.exec();
}
