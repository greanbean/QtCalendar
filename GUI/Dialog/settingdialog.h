#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include "../../CalManager/CalManager.h"

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SettingDialog(ICalManager* _calManager, QWidget *parent = 0);
	~SettingDialog();

private slots:
	void on_loadButton_clicked();
	void on_saveButton_clicked();

private:
	Ui::SettingDialog *ui;
	ICalManager* calManager;
};

#endif // SETTINGDIALOG_H