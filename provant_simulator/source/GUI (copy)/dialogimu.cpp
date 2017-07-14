#include "dialogimu.h"
#include "ui_dialogimu.h"

#include"Business/model.h"

DialogIMU::DialogIMU(Model model,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogIMU)
{
    ui->setupUi(this);
    registry = model;
    std::vector<link_DA> data = registry.actualmodel->model.GetListsLinks();

    for(uint i = 0;i<data.size();i++)
    {
        ui->comboBox->addItem(QString::fromStdString(data.at(i).name));
    }
}

DialogIMU::~DialogIMU()
{
    delete ui;
}

void DialogIMU::on_buttonBox_accepted()
{
    topic = ui->lineEdit_4->text();
    link = QString::number(ui->comboBox->currentIndex());
    noise = ui->comboBox_2->currentText();
}
