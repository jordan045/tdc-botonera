#include <QCoreApplication>
#include <QtTest>

// add necessary includes here
#include "formatconcentrator.h"
#include "stubestado.h"

class formatConcentratorTest : public QObject
{
    Q_OBJECT

public:
    formatConcentratorTest();
    ~formatConcentratorTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case01();
};

formatConcentratorTest::formatConcentratorTest() {}

formatConcentratorTest::~formatConcentratorTest() {}

void formatConcentratorTest::initTestCase() {}

void formatConcentratorTest::cleanupTestCase() {}

void formatConcentratorTest::test_case01() {
    FormatConcentrator* concentrator = new FormatConcentrator();
    StubEstado* stubEstado = new StubEstado();

    QBitArray* localTest = concentrator->getMessage(stubEstado);
    QBitArray* expected = new QBitArray(192);
    //expected->setBit(0,true);

    QCOMPARE(*localTest, *expected);

    delete localTest;
    delete expected;
}

QTEST_MAIN(formatConcentratorTest)

#include "tst_formatconcentratortest.moc"
