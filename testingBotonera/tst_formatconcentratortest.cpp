#include <QCoreApplication>
#include <QtTest>
#include <QString>

#include "formatconcentrator.h"
#include "driverestado.h"
#include "bitarrayutils.h"

class formatConcentratorTest : public QObject
{
    Q_OBJECT

public:
    formatConcentratorTest();
    ~formatConcentratorTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case_allEmpty_data();
    void test_case_allEmpty();
    void test_case_isolatedBitTesting_data();
    void test_case_isolatedBitTesting();
    void test_case_fromBinaryCaptures_data();
    void test_case_fromBinaryCaptures();
};

formatConcentratorTest::formatConcentratorTest() {}

formatConcentratorTest::~formatConcentratorTest() {}

void formatConcentratorTest::initTestCase() {}

void formatConcentratorTest::cleanupTestCase() {}

void formatConcentratorTest::test_case_allEmpty_data(){
    QTest::addColumn<QString>("range");
    QTest::addColumn<QString>("displaySelection");
    QTest::addColumn<QString>("threatAssessment");
    QTest::addColumn<QString>("center");
    QTest::addColumn<QString>("displayMode");
    QTest::addColumn<QString>("qek");
    QTest::addColumn<QString>("icm");
    QTest::addColumn<QString>("overlay");

    QTest::addColumn<QString>("qekS");
    QTest::addColumn<QString>("centerS");
    QTest::addColumn<QString>("icmS");
    QTest::addColumn<QString>("overlayS");

    QTest::addColumn<QBitArray>("result");

    QTest::newRow("TST-0001")   << "RANGE2 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");
}

void formatConcentratorTest::test_case_allEmpty() {
    QFETCH(QString, range);
    QFETCH(QString, displaySelection);
    QFETCH(QString, threatAssessment);
    QFETCH(QString, center);
    QFETCH(QString, displayMode);
    QFETCH(QString, qek);
    QFETCH(QString, icm);
    QFETCH(QString, overlay);

    QFETCH(QString, qekS);
    QFETCH(QString, centerS);
    QFETCH(QString, icmS);
    QFETCH(QString, overlayS);

    QFETCH(QBitArray, result);

    FormatConcentrator* concentrator = new FormatConcentrator();
    DriverEstado* driverEstado = new DriverEstado();
    bool comparisonResult;
    QBitArray* localTest;

    driverEstado->setRange(range);
    driverEstado->setDisplaySelection(displaySelection);
    driverEstado->setThreat(threatAssessment);
    driverEstado->setCenter(center);
    driverEstado->setDisplayMode(displayMode);
    driverEstado->setQEK(qek);
    driverEstado->setICM(icm);
    driverEstado->setOverlay(overlay);

    driverEstado->setQEKS(qekS);
    driverEstado->setCenterS(centerS);
    driverEstado->setICMS(icmS);
    driverEstado->setOverlayS(overlayS);

    localTest = concentrator->getMessage(driverEstado);

    comparisonResult = ((*localTest) == result);
    QVERIFY2(comparisonResult, qPrintable(BitArrayUtils::compareBitArrays((*localTest), result)));

    delete concentrator;
    delete driverEstado;
    delete localTest;
}

void formatConcentratorTest::test_case_isolatedBitTesting_data(){
    QTest::addColumn<QString>("range");
    QTest::addColumn<QString>("displaySelection");
    QTest::addColumn<QString>("threatAssessment");
    QTest::addColumn<QString>("center");
    QTest::addColumn<QString>("displayMode");
    QTest::addColumn<QString>("qek");
    QTest::addColumn<QString>("icm");
    QTest::addColumn<QString>("overlay");

    QTest::addColumn<QString>("qekS");
    QTest::addColumn<QString>("centerS");
    QTest::addColumn<QString>("icmS");
    QTest::addColumn<QString>("overlayS");

    QTest::addColumn<QBitArray>("result");

    //---- OVERLAY

    QTest::newRow("TST-0002")   << "RANGE2 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0010"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000101110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0003")   << "RANGE2 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000111110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0004")   << "RANGE2 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0100"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111001001110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0005")   << "RANGE2 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0101"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111001011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0006")   << "RANGE2 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0110"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111001101110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0007")   << "RANGE2 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0111"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111001111110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0008")   << "RANGE2 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "1000"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111010001110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin overlay

    //---- RANGE

    QTest::newRow("TST-0009")   << "RANGE4 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("001000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0010")   << "RANGE8 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("010000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0011")   << "RANGE16 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("011000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0012")   << "RANGE32 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("100000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0013")   << "RANGE64 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("101000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0014")   << "RANGE128 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("110000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0015")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin range

    //---- DISPLAY SELECTION

    QTest::newRow("TST-0016")   << "RANGE2 "    //range
                              << "AIR"           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000100000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0017")   << "RANGE2 "    //range
                              << "SURF"           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000010000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0018")   << "RANGE2 "    //range
                              << "SUB_SURF"           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000001000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0019")   << "RANGE2 "    //range
                              << "REF_POS"           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000100000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0020")   << "RANGE2 "    //range
                              << "BEAR_SEL"           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000010000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0021")   << "RANGE2 "    //range
                              << "LINK_SEL"           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000001000000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0022")   << "RANGE2 "    //range
                              << "WARF_SEL"           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000100000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0023")   << "RANGE2 "    //range
                              << "FIG"           //displaySelection
                              << ""           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << ""           //icm
                              << "0001"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000010000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin display selection

    //---- THREAT ASSESSMENT

    QTest::newRow("TST-0024")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << "12_SEC"       //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000001000000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0025")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << "30_SEC"       //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000100000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0026")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << "6_MIN"       //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000010000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0027")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << "15_MIN"       //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000001000000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0028")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << "RESET"       //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000100000000000000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin threat assessment

    //---- CENTER

    QTest::newRow("TST-0029")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << "CU_OR_OFF_CENT"             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000100000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0030")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << "CU_OR_CENT"             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000010000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0031")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << "OFF_CENT"             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000001000000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0032")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << "CENT"             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000100000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0033")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << "RESET_OBM"             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000010000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0034")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << "DATA_REQ"             //center
                              << ""             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000001000000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin center

    //---- DISPLAY MODE

    QTest::newRow("TST-0035")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << "RR"             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000100000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0036")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << "OWN_CURS"             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000010000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0037")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << "TM"             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000100000000000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0038")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << "SYST_ALARM"             //displayMode
                              << ""             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000001000000000010000000100000000000000000000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin display mode

    //---- QEK

    QTest::newRow("TST-0039")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_20"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000100000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0040")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_21"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000100010000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0041")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_22"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000100100000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0042")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_23"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000100110000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0043")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_24"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000101000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0044")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_25"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000101010000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0045")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_26"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000101100000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0046")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_27"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000101110000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0047")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_30"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000110000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0048")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_31"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000110010000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0049")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_32"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000110100000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0050")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_33"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000110110000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0051")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_34"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000111000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0052")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_35"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000111010000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0053")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_36"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000111100000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0054")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_37"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000111110000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0055")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_40"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001000000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0056")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_41"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001000010000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0057")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_42"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001000100000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0058")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_43"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001000110000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0059")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_44"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001001000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0060")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_45"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001001010000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0061")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_46"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001001100000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0062")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_47"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001001110000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0063")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_50"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001010000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0064")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_51"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001010010000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0065")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_52"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001010100000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0066")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_53"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001010110000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0067")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_54"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001011000000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0068")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_55"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001011010000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0069")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_56"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001011100000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0070")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << "QEK_57"             //qek
                              << ""             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000001011110000000000000000111000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin qek

    //---- ICM

    QTest::newRow("TST-0071")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << "1"             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000000000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0072")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << "2"             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000001000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0073")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << "3"             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000010000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0074")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << "4"             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000011000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0075")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << "5"             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000100000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0076")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << "6"             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000101000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0077")   << "RANGE2 "    //range
                              << ""             //displaySelection
                              << ""             //threatAssessment
                              << ""             //center
                              << ""             //displayMode
                              << ""             //qek
                              << "7"             //icm
                              << "0001"         //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << ""       //icmS
                              << "0001"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000110000011110000100000000000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin icm

}

void formatConcentratorTest::test_case_isolatedBitTesting(){
    QFETCH(QString, range);
    QFETCH(QString, displaySelection);
    QFETCH(QString, threatAssessment);
    QFETCH(QString, center);
    QFETCH(QString, displayMode);
    QFETCH(QString, qek);
    QFETCH(QString, icm);
    QFETCH(QString, overlay);

    QFETCH(QString, qekS);
    QFETCH(QString, centerS);
    QFETCH(QString, icmS);
    QFETCH(QString, overlayS);

    QFETCH(QBitArray, result);

    FormatConcentrator* concentrator = new FormatConcentrator();
    DriverEstado* driverEstado = new DriverEstado();
    bool comparisonResult;
    QBitArray* localTest;

    driverEstado->setRange(range);
    driverEstado->setDisplaySelection(displaySelection);
    driverEstado->setThreat(threatAssessment);
    driverEstado->setCenter(center);
    driverEstado->setDisplayMode(displayMode);
    driverEstado->setQEK(qek);
    driverEstado->setICM(icm);
    driverEstado->setOverlay(overlay);

    driverEstado->setQEKS(qekS);
    driverEstado->setCenterS(centerS);
    driverEstado->setICMS(icmS);
    driverEstado->setOverlayS(overlayS);

    localTest = concentrator->getMessage(driverEstado);

    comparisonResult = ((*localTest) == result);
    QVERIFY2(comparisonResult, qPrintable(BitArrayUtils::compareBitArrays((*localTest), result)));

    delete concentrator;
    delete driverEstado;
    delete localTest;
}

void formatConcentratorTest::test_case_fromBinaryCaptures_data(){
    QTest::addColumn<QString>("range");
    QTest::addColumn<QString>("displaySelection");
    QTest::addColumn<QString>("threatAssessment");
    QTest::addColumn<QString>("center");
    QTest::addColumn<QString>("displayMode");
    QTest::addColumn<QString>("qek");
    QTest::addColumn<QString>("icm");
    QTest::addColumn<QString>("overlay");

    QTest::addColumn<QString>("qekS");
    QTest::addColumn<QString>("centerS");
    QTest::addColumn<QString>("icmS");
    QTest::addColumn<QString>("overlayS");

    QTest::addColumn<QBitArray>("result");

    QTest::newRow("TST-0078")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << ""           //center
                              << "OWN_CURS TM"           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000000000110000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0079")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << "OFF_CENT"           //center
                              << "OWN_CURS TM"           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000001000110000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0080")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << "CENT"           //center
                              << "OWN_CURS TM"           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000000100110000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0081")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << "RESET_OBM"           //center
                              << "OWN_CURS TM"           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000000010110000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0082")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000000000000000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0083")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << ""           //center
                              << "OWN_CURS"           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000000000010000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0084")   << "RANGE256 "    //range
                              << "AIR SURF SUB_SURF REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111111111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0085")   << "RANGE256 "    //range
                              << "SUB_SURF REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111001111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0086")   << "RANGE256 "    //range
                              << "REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0087")   << "RANGE256 "    //range
                              << "BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000011110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0088")   << "RANGE256 "    //range
                              << "LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000001110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0089")   << "RANGE256 "    //range
                              << "WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0090")   << "RANGE256 "    //range
                              << "FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000010010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0091")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0092")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "1"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000010000000000000000000000000000000000010000000100000000000000000000000000000000000000000000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0093")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "2"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000010000000000000000000000000000000000010000000100000000000000000000000000000000000000001000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0094")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "4"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000010000000000000000000000000000000000010000000100000000000000000000000000000000000000011000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0095")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "5"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000010000000000000000000000000000000000010000000100000000000000000000000000000000000000100000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0096")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "6"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000010000000000000000000000000000000000010000000100000000000000000000000000000000000000101000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0097")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000010000000000000000000000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0098")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << ""           //center
                              << "OWN_CURS TM"           //displayMode
                              << "QEK_20"           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000000000110000000000000000010000000100000000000000000100000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0099")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << ""           //center
                              << "OWN_CURS TM"           //displayMode
                              << "QEK_21"           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000000000110000000000000000010000000100000000000000000110000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0100")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << ""           //center
                              << "OWN_CURS TM"           //displayMode
                              << "QEK_40"           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000000000110000000000000000010000000100000000000000001000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0101")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "RESET"           //threatAssessment
                              << ""           //center
                              << "OWN_CURS TM"           //displayMode
                              << "QEK_41"           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000000100000000000000110000000000000000010000000100000000000000001010000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0102")   << "RANGE64 "    //range
                              << "AIR SURF SUB_SURF REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("101111111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0103")   << "RANGE2 "    //range
                              << "AIR SURF SUB_SURF REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("000111111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0104")   << "RANGE4 "    //range
                              << "AIR SURF SUB_SURF REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("001111111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0105")   << "RANGE8 "    //range
                              << "AIR SURF SUB_SURF REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("010111111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0106")   << "RANGE16 "    //range
                              << "AIR SURF SUB_SURF REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("011111111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0107")   << "RANGE32 "    //range
                              << "AIR SURF SUB_SURF REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("100111111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0108")   << "RANGE128 "    //range
                              << "AIR SURF SUB_SURF REF_POS BEAR_SEL LINK_SEL WARF_SEL FIG"           //displaySelection
                              << "6_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "3"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("110111111110010000000000000000000000000000000000010000000100000000000000000000000000000000000000010000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0109")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "30_SEC"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000100000000000000000000000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0110")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "12_SEC"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000001000000000000000000000000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("TST-0111")   << "RANGE256 "    //range
                              << ""           //displaySelection
                              << "15_MIN"           //threatAssessment
                              << ""           //center
                              << ""           //displayMode
                              << ""           //qek
                              << "7"           //icm
                              << "0011"       //overlay
                              << ""       //qekS
                              << ""       //centerS
                              << "3"       //icmS
                              << "0100"       //overlayS
                              << BitArrayUtils::qBitArrayfromString("111000000000001000000000000000000000000000000000010000000100000000000000000000000000000000000000110000110100010000000000000000000000000000000000000000000000000000000000000000000000000000000000");


}

void formatConcentratorTest::test_case_fromBinaryCaptures() {
    QFETCH(QString, range);
    QFETCH(QString, displaySelection);
    QFETCH(QString, threatAssessment);
    QFETCH(QString, center);
    QFETCH(QString, displayMode);
    QFETCH(QString, qek);
    QFETCH(QString, icm);
    QFETCH(QString, overlay);

    QFETCH(QString, qekS);
    QFETCH(QString, centerS);
    QFETCH(QString, icmS);
    QFETCH(QString, overlayS);

    QFETCH(QBitArray, result);

    FormatConcentrator* concentrator = new FormatConcentrator();
    DriverEstado* driverEstado = new DriverEstado();
    bool comparisonResult;
    QBitArray* localTest;

    driverEstado->setRange(range);
    driverEstado->setDisplaySelection(displaySelection);
    driverEstado->setThreat(threatAssessment);
    driverEstado->setCenter(center);
    driverEstado->setDisplayMode(displayMode);
    driverEstado->setQEK(qek);
    driverEstado->setICM(icm);
    driverEstado->setOverlay(overlay);

    driverEstado->setQEKS(qekS);
    driverEstado->setCenterS(centerS);
    driverEstado->setICMS(icmS);
    driverEstado->setOverlayS(overlayS);

    localTest = concentrator->getMessage(driverEstado);

    comparisonResult = ((*localTest) == result);
    QVERIFY2(comparisonResult, qPrintable(BitArrayUtils::compareBitArrays((*localTest), result)));

    delete concentrator;
    delete driverEstado;
    delete localTest;
}

QTEST_MAIN(formatConcentratorTest)

#include "tst_formatconcentratortest.moc"
