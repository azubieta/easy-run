// library
#include <QIcon>
#include <QFile>
#include <QProcess>
#include <QFileInfo>
#include <QDebug>
#include <QApplication>
#include <QCommandLineParser>

#include "MainDialog.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QApplication::setApplicationName("rundialog-qt");
    QApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Binaries execution utility");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("binary", QCoreApplication::translate("main", "File to be executed."));

    // Process the actual command line arguments given by the user
    parser.process(app);

    const QStringList args = parser.positionalArguments();
    if (args.isEmpty())
        parser.showHelp(1);

    QFile target(args.first());
    if (!target.exists()) {
        qWarning() << "File not found " + args.first();
        return 1;
    }

    QFileInfo targetInfo(target);
    MainDialog dialog;

    dialog.setWindowIcon(QIcon::fromTheme("gtk-execute"));
    dialog.setWindowTitle("Execute " + targetInfo.fileName());
    dialog.show();

    QObject::connect(&dialog, &QDialog::accepted, [&target] {
        QFileDevice::Permissions permisions = target.permissions();
        target.setPermissions(permisions | QFileDevice::ExeOwner);

        QProcess process;
        process.startDetached(target.fileName());
    });

    return QApplication::exec();
}
