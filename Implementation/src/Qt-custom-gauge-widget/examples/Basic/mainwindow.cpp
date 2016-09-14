/***************************************************************************
**                                                                        **
**  QcGauge, for instrumentation, and real time data measurement          **
**  visualization widget for Qt.                                          **
**  Copyright (C) 2015 Hadj Tahar Berrima                                 **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU Lesser General Public License as        **
**  published by the Free Software Foundation, either version 3 of the    **
**  License, or (at your option) any later version.                       **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU Lesser General Public License for more details.                   **
**                                                                        **
**  You should have received a copy of the GNU Lesser General Public      **
**  License along with this program.                                      **
**  If not, see http://www.gnu.org/licenses/.                             **
**                                                                        **
****************************************************************************
**           Author:  Hadj Tahar Berrima                                  **
**           Website: http://pytricity.com/                               **
**           Contact: berrima_tahar@yahoo.com                             **
**           Date:    1 dec 2014                                          **
**           Version:  1.0                                                **
****************************************************************************/

#include <mainwindow.h>
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet( "background-color: black; ");
    mAirspeedGauge = new QcGaugeWidget;
    QcArcItem *arc = mAirspeedGauge->addArc(65);
    arc->setColor( Qt::white );
    DegreesArc= mAirspeedGauge->addDegrees(75);
    DegreesArc->setValueRange(0,200);
    DegreesArc->setColor( Qt::white);
    clrBand = mAirspeedGauge->addColorBand(70);
    clrBand->setValueRange(0,200);
    QcValuesItem *values = mAirspeedGauge->addValues(90);
    values->setValueRange(0,200);
    values->setColor( Qt::white );
    unit = mAirspeedGauge->addLabel(70);
    unit->setText( "Km/h" );
    unit->setColor( Qt::white );
    QcLabelItem *lab = mAirspeedGauge->addLabel(40);
    lab->setText("0");
    lab->setColor( Qt::white );
    mAirspeedNeedle = mAirspeedGauge->addNeedle(75);
    mAirspeedNeedle->setLabel(lab);
    mAirspeedNeedle->setColor(Qt::red);

    mAirspeedNeedle->setValueRange(0, 200);

    mAirspeedGauge->addBackground(7);
    ui->horizontalLayout->addWidget(mAirspeedGauge);

    skt = new ClientConnection();
    connect( skt, SIGNAL(newData(int16_t,int8_t)), this, SLOT( setValue(int16_t,int8_t))  );

    skt->connectToServer();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setValue(qint8 id, qint16 value, qint8 unitSel )
{

    switch( id )
    {

        case  ID_GAGE_SPEED:
        // set value

        mAirspeedNeedle->setCurrentValue( value );
        switch ( unitSel )
        {
        // input 0 - 2000
            case KPH:
                mAirspeedNeedle->setValueRange(0, 200 );
                clrBand->setColorsSegments( Qt::green, 0,
                                            Qt::darkGreen, 140,
                                            Qt::red, 200 );
                unit->setText("Km/h");
                DegreesArc->setStep( 10 );
            break;
            case MPH:
                mAirspeedNeedle->setValueRange(0, 120);
                clrBand->setColorsSegments( Qt::green, 0,
                                            Qt::darkGreen, 90,
                                            Qt::red, 120 );
                unit->setText("Mi/h");
                DegreesArc->setStep( 10 );
                break;
        }
        break;


        case ID_GAGE_TACHO:

        //input 0 - 8000
            mAirspeedNeedle->setCurrentValue( value );

            mAirspeedNeedle->setValueRange(0, 8000);
            clrBand->setColorsSegments( Qt::green, 0,
                                        Qt::darkGreen, 1000,
                                        Qt::red, 5000 );
            DegreesArc->setStep( 1000 );
            // only one type of units
            unit->setText("RPM");

        break;

        case ID_GAGE_FUEL:
        // temporary setup, maybe change look and feel later

            mAirspeedNeedle->setValueRange(0, 100 );
            clrBand->setColorsSegments( Qt::red, 0,
                                        Qt::darkGreen, 80,
                                        Qt::green, 100 );
            mAirspeedNeedle->setCurrentValue( value );
            DegreesArc->setStep( 25 );
            // marks range 20 - 90 degrees ->  0% 25% 50% 75% 100%

            switch ( unitSel )
            {
            // input 0 - 1000
                case LTS:
                    unit->setText("lts");
                break;

                case GAL:
                    unit->setText("Gal");
                break;

            }

            break;

        default:

            break;

    }
}
