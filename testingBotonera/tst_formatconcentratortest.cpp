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
    QTest::addColumn<QString>("overlay");
    QTest::addColumn<QString>("range");
    QTest::addColumn<QBitArray>("result");

    QTest::newRow("") << "0001" << "RANGE2" << BitArrayUtils::qBitArrayfromString("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000");
}

void formatConcentratorTest::test_case01() {
    QFETCH(QString, overlay);
    QFETCH(QString, range);
    QFETCH(QBitArray, result);

    FormatConcentrator* concentrator = new FormatConcentrator();
    StubEstado* stubEstado = new StubEstado();

    stubEstado->setOverlay(overlay);
    stubEstado->setRange(range);
    QBitArray* localTest = concentrator->getMessage(stubEstado);

    QCOMPARE(*localTest, result);

    delete localTest;
}

QTEST_MAIN(formatConcentratorTest)

#include "tst_formatconcentratortest.moc"
