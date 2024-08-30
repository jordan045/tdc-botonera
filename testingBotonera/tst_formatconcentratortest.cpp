#include <QCoreApplication>
#include <QtTest>

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
    void test_case01_data();
    void test_case01();
};

formatConcentratorTest::formatConcentratorTest() {}

formatConcentratorTest::~formatConcentratorTest() {}

void formatConcentratorTest::initTestCase() {}

void formatConcentratorTest::cleanupTestCase() {}

void formatConcentratorTest::test_case01_data(){
    QTest::addColumn<QString>("range");
    QTest::addColumn<QString>("displaySelection");
    QTest::addColumn<QString>("threatAssessment");
    QTest::addColumn<QString>("center");
    QTest::addColumn<QString>("displayMode");
    QTest::addColumn<QString>("qek");
    QTest::addColumn<QString>("icm");
    QTest::addColumn<QString>("overlay");
    QTest::addColumn<QBitArray>("result");

    QTest::newRow("")   << "RANGE2"
                        << "air"
                        << "12_sec"
                        << "CU_OR_OFF_CENT"
                        << "RR"
                        << "QEK_20"
                        << "1"
                        << "0001"
                        << BitArrayUtils::qBitArrayfromString("000000000000100000001000000000001000000000000001000000000000000000000000000000000000000000001000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000");
}

void formatConcentratorTest::test_case01() {
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

    stubEstado->setRange(range);
    stubEstado->setDisplaySelection(displaySelection);
    stubEstado->setThreat(threatAssessment);
    stubEstado->setCenter(center);
    stubEstado->setDisplayMode(displayMode);
    stubEstado->setQEK(qek);
    stubEstado->setICM(icm);
    stubEstado->setOverlay(overlay);

    QBitArray* localTest = concentrator->getMessage(stubEstado);

    QCOMPARE(*localTest, result);

    delete localTest;
}

QTEST_MAIN(formatConcentratorTest)

#include "tst_formatconcentratortest.moc"
