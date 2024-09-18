#include <QCoreApplication>
#include <QtTest>
#include <QString>

#include "formatconcentrator.h"
#include "stubestado.h"
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
    QTest::addColumn<QBitArray>("result");

    QTest::newRow("8")   << "RANGE2 "    //range
                        << ""           //displaySelection
                        << ""           //threatAssessment
                        << ""           //center
                        << ""           //displayMode
                        << ""           //qek
                        << ""           //icm
                        << "0001"       //overlay
                        << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");
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
    QFETCH(QBitArray, result);

    FormatConcentrator* concentrator = new FormatConcentrator();
    StubEstado* stubEstado = new StubEstado();
    bool comparisonResult;
    QBitArray* localTest;

    stubEstado->setRange(range);
    stubEstado->setDisplaySelection(displaySelection);
    stubEstado->setThreat(threatAssessment);
    stubEstado->setCenter(center);
    stubEstado->setDisplayMode(displayMode);
    stubEstado->setQEK(qek);
    stubEstado->setICM(icm);
    stubEstado->setOverlay(overlay);

    localTest = concentrator->getMessage(stubEstado);

    comparisonResult = ((*localTest) == result);
    QVERIFY2(comparisonResult, qPrintable(BitArrayUtils::compareBitArrays((*localTest), result)));

    delete concentrator;
    delete stubEstado;
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
    QTest::addColumn<QBitArray>("result");

    //---- OVERLAY

    QTest::newRow("10")   << "RANGE2 "    //range
                        << ""           //displaySelection
                        << ""           //threatAssessment
                        << ""           //center
                        << ""           //displayMode
                        << ""           //qek
                        << ""           //icm
                        << "0010"       //overlay
                        << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("11")   << "RANGE2 "    //range
                        << ""           //displaySelection
                        << ""           //threatAssessment
                        << ""           //center
                        << ""           //displayMode
                        << ""           //qek
                        << ""           //icm
                        << "0011"       //overlay
                        << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("12")   << "RANGE2 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0100"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("13")   << "RANGE2 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0101"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010100111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("14")   << "RANGE2 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0110"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001100111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("15")   << "RANGE2 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0111"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011100111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("16")   << "RANGE2 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "1000"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010111000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin overlay

    //---- RANGE

    QTest::newRow("17")   << "RANGE4 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("18")   << "RANGE8 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("19")   << "RANGE16 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("20")   << "RANGE32 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("21")   << "RANGE64 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000101000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("22")   << "RANGE128 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000011000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("23")   << "RANGE256 "    //range
                      << ""           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin range

    //---- DISPLAY SELECTION

    QTest::newRow("24")   << "RANGE2 "    //range
                      << "AIR"           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("25")   << "RANGE2 "    //range
                      << "SURF"           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("26")   << "RANGE2 "    //range
                      << "SUB_SURF"           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("27")   << "RANGE2 "    //range
                      << "REF_POS"           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("28")   << "RANGE2 "    //range
                      << "BEAR_SEL"           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("29")   << "RANGE2 "    //range
                      << "LINK_SEL"           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("30")   << "RANGE2 "    //range
                      << "WARF_SEL"           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("31")   << "RANGE2 "    //range
                      << "FIG"           //displaySelection
                      << ""           //threatAssessment
                      << ""           //center
                      << ""           //displayMode
                      << ""           //qek
                      << ""           //icm
                      << "0001"       //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin display selection

    //---- THREAT ASSESSMENT

    QTest::newRow("32")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << "12_SEC"       //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("33")   << "RANGE2 "    //range
                        << ""             //displaySelection
                        << "30_SEC"       //threatAssessment
                        << ""             //center
                        << ""             //displayMode
                        << ""             //qek
                        << ""             //icm
                        << "0001"         //overlay
                        << BitArrayUtils::qBitArrayfromString("000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("34")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << "6_MIN"       //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("35")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << "15_MIN"       //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("36")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << "RESET"       //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin threat assessment

    //---- CENTER

    QTest::newRow("37")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << "CU_OR_OFF_CENT"             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("38")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << "CU_OR_CENT"             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("39")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << "OFF_CENT"             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("40")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << "CENT"             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("41")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << "RESET_OBM"             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("42")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << "DATA_REQ"             //center
                      << ""             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin center

    //---- DISPLAY MODE

    QTest::newRow("43")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << "RR"             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("44")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << "OWN_CURS"             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("45")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << "TM"             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("46")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << "SYST_ALARM"             //displayMode
                      << ""             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin display mode

    //---- QEK

    QTest::newRow("47")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_20"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("48")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_21"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010001000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("49")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_22"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001001000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("50")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_23"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011001000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("51")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_24"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000101000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("52")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_25"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010101000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("53")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_26"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001101000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("54")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_27"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011101000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("55")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_30"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("56")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_31"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010011000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("57")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_32"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001011000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("58")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_33"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011011000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("59")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_34"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("60")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_35"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010111000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("61")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_36"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("62")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_37"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111000000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("63")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_40"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("64")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_41"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("65")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_42"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("66")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_43"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011000100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("67")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_44"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("68")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_45"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010100100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("69")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_46"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001100100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("70")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_47"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011100100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("71")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_50"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("72")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_51"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010010100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("73")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_52"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001010100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("74")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_53"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011010100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("75")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_54"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000110100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("76")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_55"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010110100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("77")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_56"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001110100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("78")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << "QEK_57"             //qek
                      << ""             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011110100000000000000000010000111000000000000000000000000000000000000000000000000000000000000000000000000");

    //-- fin qek

    //---- ICM

    QTest::newRow("79")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << "1"             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("80")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << "2"             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000100000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("81")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << "3"             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000010000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("82")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << "4"             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000110000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("83")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << "5"             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000001000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("84")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << "6"             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000101000000000000000000000000000000000000000000000000000000000000000000000000");

    QTest::newRow("85")   << "RANGE2 "    //range
                      << ""             //displaySelection
                      << ""             //threatAssessment
                      << ""             //center
                      << ""             //displayMode
                      << ""             //qek
                      << "7"             //icm
                      << "0001"         //overlay
                      << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000011000000000000000000000000000000000000000000000000000000000000000000000000");

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
    QFETCH(QBitArray, result);

    FormatConcentrator* concentrator = new FormatConcentrator();
    StubEstado* stubEstado = new StubEstado();
    bool comparisonResult;
    QBitArray* localTest;

    stubEstado->setRange(range);
    stubEstado->setDisplaySelection(displaySelection);
    stubEstado->setThreat(threatAssessment);
    stubEstado->setCenter(center);
    stubEstado->setDisplayMode(displayMode);
    stubEstado->setQEK(qek);
    stubEstado->setICM(icm);
    stubEstado->setOverlay(overlay);

    localTest = concentrator->getMessage(stubEstado);

    comparisonResult = ((*localTest) == result);
    QVERIFY2(comparisonResult, qPrintable(BitArrayUtils::compareBitArrays((*localTest), result)));

    delete concentrator;
    delete stubEstado;
    delete localTest;
}

QTEST_MAIN(formatConcentratorTest)

#include "tst_formatconcentratortest.moc"
