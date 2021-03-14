#pragma once
#ifndef _MSGHANDLER_H_
#define _MSGHANDLER_H_
#include <QtGlobal>
#include <QFile>
#include <QDateTime>

void msgToFile(QtMsgType type,
			   const QMessageLogContext& context,
			   const QString& msg) {
	QFile file("protocol.log");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return;

	QString strDateTime = QDateTime::currentDateTime().toString("dd.MM.yy-hh::mm::ss");
	QTextStream out(&file);

	switch (type) {
	case QtDebugMsg:
		out << strDateTime << " Debug: " << msg << ", " << context.file << '\n';
		break;
	case QtWarningMsg:
		out << strDateTime << " Warning: " << msg << ", " << context.file << '\n';
		break;
	case QtCriticalMsg:
		out << strDateTime << " Critical: " << msg << ", " << context.file << '\n';
		break;
	case QtFatalMsg:
		out << strDateTime << " Fatal: " << msg << ", " << context.file << '\n';
		abort();
	}
}

void dummyOutput(QtMsgType, const QMessageLogContext&, const QString&) {}

#endif //_MSGHANDLER_H_
