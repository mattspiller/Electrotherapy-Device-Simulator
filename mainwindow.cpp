#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "battery.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem("Programs");
    ui->listWidget->addItem("Frequency");
    ui->listWidget->addItem("Settings");

    ui->listWidget->setCurrentRow(0); //sets current item in display (list) to the item below it

    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(skinOff()));
    timer.setHMS(0,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::skinOff() //Runs during treatment
{
     time->start(1000); // timer starts

    ui->listWidget->clear();

    timer = timer.addSecs(1); // adds 1 second
    QString stringTime = timer.toString("hh : mm : ss"); // converts the time object to a string
    ui->listWidget->insertItem(0,"SKIN ON");
    ui->listWidget->insertItem(1, stringTime);

    //if the number of seconds that has past during treatment is divisble by the rate of battery loss
    if((timer.hour() * 3600 + timer.minute() * 60 + timer.second()) % battery.getRateOfBatteryLoss() == 0)
    {
        battery.reduceBatteryLevel(); //battery level drops by 1%
        ui->batteryLevel->setValue(battery.getBatteryLevel()); //updates the battery level in the ui

        if(battery.getBatteryLevel() < 1) //if battery level drops to zero (if the battery dies)
        {
            ui->listWidget->close(); //turn off the display permanently
        }
    }
}
void MainWindow::on_pushButton_5_clicked() // OK button is clicked
{
    if(battery.getPowerLevel() == 0 && ui->listWidget->isVisible()) //if treatment is not running, and the simulated device is ON
    {
        QListWidgetItem *item = ui->listWidget->currentItem();

        if(item->text() == "Programs"){ //if "Programs" is selected
            ui->listWidget->clear();
            ui->listWidget->addItem("Pain");
            ui->listWidget->addItem("Head");
            ui->listWidget->addItem("Cold");
            ui->listWidget->addItem("Trauma");

            //ensures that after "Programs" is selected, that the first item, "Pain", is the currently highlighted item
            ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
        }

       else if(item->text() == "Frequency"){ //if "Frequency" is selected
            ui->listWidget->clear();
            ui->listWidget->addItem("9Hz - 10Hz");
            ui->listWidget->addItem("20Hz");
            ui->listWidget->addItem("40Hz");
            ui->listWidget->addItem("60Hz");
            ui->listWidget->addItem("80Hz");
            ui->listWidget->addItem("100Hz");
            ui->listWidget->addItem("120Hz");

            //ensures that after "Frequency" is selected, that the first item, "9Hz - 10Hz", is the currently highlighted item
            ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
        }

        else if(item->text() == "Settings"){ //if "Settings" is selected
             ui->listWidget->clear();
             ui->listWidget->addItem("Brightness");
             ui->listWidget->addItem("Children Mode");
             ui->listWidget->addItem("Economy");
             ui->listWidget->addItem("Sound");
            // ui->listWidget->setItemWidget(item, )

             //ensures that after "Settings" is selected, that the first item, "Brightness", is the currently highlighted item
             ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
         }

        else if(item->text() == "Pain"){ //if "Pain" is selected
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }

        else if(item->text() == "Head"){ //if "Head" is selected
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }

        else if(item->text() == "Cold"){ //if "Cold" is selected
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
          }

        else if(item->text() == "Trauma"){ //if "Trauma" is selected
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }

        else if(item->text() == "Brightness"){ //if "Brightness" is selected
            ui->listWidget->clear();
            ui->listWidget->addItem("1");
            ui->listWidget->addItem("2");
            ui->listWidget->addItem("3");
            ui->listWidget->addItem("4");
            ui->listWidget->addItem("5");
            ui->listWidget->addItem("6");
            ui->listWidget->addItem("7");
            ui->listWidget->addItem("8");
            ui->listWidget->addItem("9");
            ui->listWidget->addItem("10");
            //ui->listWidget->setFlow(LeftToRight);

            ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
        }

        else if(item->text() == "Children Mode"){ //if "Children Mode" is selected
            ui->listWidget->clear();
            ui->listWidget->addItem("ON");
            ui->listWidget->addItem("OFF");

            ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
        }

        else if(item->text() == "Economy"){ //if "Economy" is selected
            ui->listWidget->clear();
            ui->listWidget->addItem("ON");
            ui->listWidget->addItem("OFF");

            ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
        }

        else if(item->text() == "Sound"){ //if "Sound" is selected
            ui->listWidget->clear();
            ui->listWidget->addItem("1");
            ui->listWidget->addItem("2");
            ui->listWidget->addItem("3");
            ui->listWidget->addItem("4");
            ui->listWidget->addItem("5");
            ui->listWidget->addItem("6");
            ui->listWidget->addItem("7");
            ui->listWidget->addItem("8");
            ui->listWidget->addItem("9");
            ui->listWidget->addItem("10");

            ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
        }

        else if (item->text() == "ON"){ //if "ON" is selected
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "OFF"){ //if "OFF" is selected
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "1"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "2"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "3"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "4"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "5"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "6"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "7"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "8"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "9"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "10"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
        }

        else if (item->text() == "9Hz - 10Hz"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }

        else if (item->text() == "20Hz"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }

        else if (item->text() == "40Hz"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }

        else if (item->text() == "60Hz"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }

        else if (item->text() == "80Hz"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }

        else if (item->text() == "100Hz"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }

        else if (item->text() == "120Hz"){
            ui->listWidget->currentItem()->setBackground(Qt :: green);
            ui->listWidget->clear();
            battery.startTreatment(); //sets power level to 1, begins battery depletion
            skinOff();
        }
    }
    else if(battery.getPowerLevel() != 0) //else if the treatment is running
    {
        if(time->isActive()) //if treatment is not paused
        {
            time->stop(); //pause treatment
            ui->listWidget->clear();
            ui->listWidget->insertItem(0,"SKIN OFF"); //change display to indicate that electrode isn't touching skin
            ui->listWidget->insertItem(1, timer.toString("hh : mm : ss"));
        }
        else //treatment is paused
        {
            time->start(1000); //unpause treatment
            ui->listWidget->clear();
            ui->listWidget->insertItem(0,"SKIN ON"); //change display to indicate that electrode is touching skin
            ui->listWidget->insertItem(1, timer.toString("hh : mm : ss"));
        }
    }
}

void MainWindow::on_pushButton_clicked() //Up Arrow button is clicked
{
    int currentIndex = ui->listWidget->currentRow();
    QListWidgetItem *item = ui->listWidget->currentItem();
    if(currentIndex == 0) //if the current item is the top item in the list, then make the next item the bottom element of the list
    {
        ui->listWidget->insertItem(ui->listWidget->count() - 1, item);
        ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
    }
    else //otherwise, make next item the item directly above the current item
    {
        ui->listWidget->insertItem(currentIndex - 1, item);
        ui->listWidget->setCurrentRow(currentIndex - 1); //sets current item in display (list) to the item above it
    }
}

void MainWindow::on_pushButton_4_clicked() //Down Arrow button is clicked
{
    int currentIndex = ui->listWidget->currentRow();
    QListWidgetItem *item = ui->listWidget->currentItem();
    if(currentIndex == ui->listWidget->count() - 1) //if the current item is the bottom item in the list, then make the next item the top item in the list
    {
        ui->listWidget->insertItem(0, item);
        ui->listWidget->setCurrentRow(0);
    }
    else //otherwise, make next item the item directly below the current item
    {
        ui->listWidget->insertItem(currentIndex+1, item);
        ui->listWidget->setCurrentRow(currentIndex + 1); //sets current item in display (list) to the item below it
    }
}

void MainWindow::on_pushButton_6_clicked() //Main Menu button is clicked
{
    if(ui->listWidget->isVisible()) //prevents main menu functionality when device is powered off
    {
        ui->listWidget->clear();
        ui->listWidget->addItem("Programs");
        ui->listWidget->addItem("Frequency");
        ui->listWidget->addItem("Settings");

        //ensures that after the "Main Menu" button is clicked, that the first item, "Programs", is the currently highlighted item
        ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);

        battery.stopTreatment(); //sets power level to 0, stops battery depletion

        time->stop();
        timer.setHMS(0,0,0);
    }
}


void MainWindow::on_pushButton_7_clicked() //ON/OFF button is clicked
{
    if(ui->listWidget->isHidden() && battery.getBatteryLevel() > 1) //if the display is off, and the battery isn't dead
    {
        ui->listWidget->show(); //turn on the display
        ui->listWidget->addItem("Programs");
        ui->listWidget->addItem("Frequency");
        ui->listWidget->addItem("Settings");

        //ensures that after the display is turned on, that the first item, "Programs", is the currently highlighted item
        ui->listWidget->setCurrentRow(ui->listWidget->currentRow() + 1);
    }
    else
    {
        ui->listWidget->hide(); //turn off the display
        ui->listWidget->clear(); //clear whatever was on the display

        time->stop();
        timer.setHMS(0,0,0);

        battery.stopTreatment(); //sets power level to 0, stops battery depletion
    }
}


void MainWindow::on_pushButton_2_clicked() //Left Arrow button is clicked
{
    if(timer.second() > 0 && time->isActive()) //if timer is running, and therefore, if treatment is active (electrode on skin)
    {
        ui->listWidget->clear();
        battery.decreasePowerLevel(); //decrement power level by a value of 1
        ui->listWidget->insertItem(0, battery.getPowerLevelString()); //display the power level string
    }
}


void MainWindow::on_pushButton_3_clicked() //Right Arrow button clicked
{
    if(timer.second() > 0 && time->isActive()) //if timer is running, and therefore, if treatment is active (electrode on skin)
    {
        ui->listWidget->clear();
        battery.increasePowerLevel(); //increment power level by a value of 1
        ui->listWidget->insertItem(0, battery.getPowerLevelString()); //display the power level string
    }
}
