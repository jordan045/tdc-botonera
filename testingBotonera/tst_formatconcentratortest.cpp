#include <QtTest>

// add necessary includes here

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

void formatConcentratorTest::test_case01() {}

QTEST_APPLESS_MAIN(formatConcentratorTest)

#include "tst_formatconcentratortest.moc"
