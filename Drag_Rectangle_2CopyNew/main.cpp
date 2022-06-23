#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <Gridview_Model.h>
#include <Listview_Model.h>
#include <MyRectangle.h>
#include <MyLable.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Lvmdl" , new Listview_Model);
    engine.rootContext()->setContextProperty("Gvmdl" , new Gridview_Model);
    qmlRegisterType<MyRectangle>("comps",1,0,"MyRect");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
