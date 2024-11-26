#include <QCoreApplication>
#include <QtTest>
#include <QString>
#include <QFile>
#include <QDebug>

#include "qjsondocument.h"
#include "formatconcentrator.h"
#include "stubestado.h"
#include "bitarrayutils.h"

class formatConcentratorTest : public QObject
{
    Q_OBJECT

public:
    formatConcentratorTest();
    ~formatConcentratorTest();

private:
    const QString JSON_FILE_PATH = ":/json/json/botoneraTestCases.json";
    QJsonObject testingJsonData;

    void readDataFromJson();
    void createTestTable();
    void addRowToTestTable(QJsonObject testCase);
    StubEstado* fetchDataFromTestTable();
    void performComparison(StubEstado* stubEstado);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_cases_data();
    void test_cases();
};

formatConcentratorTest::formatConcentratorTest() {}

formatConcentratorTest::~formatConcentratorTest() {}

void formatConcentratorTest::initTestCase() {
    readDataFromJson();
}

void formatConcentratorTest::cleanupTestCase() {}

void formatConcentratorTest::test_cases_data(){
    createTestTable();

    QJsonArray testCases = testingJsonData["formatconcentratorTestCases"].toArray();
    QJsonObject testCase;

    for (const QJsonValue &testCaseVal : testCases) {
        testCase = testCaseVal.toObject();

        addRowToTestTable(testCase);
    }
}

void formatConcentratorTest::test_cases() {
    StubEstado* stubEstado = fetchDataFromTestTable();

    performComparison(stubEstado);
}

void formatConcentratorTest::readDataFromJson(){
    QFile File(JSON_FILE_PATH);

    if(File.open(QIODevice::ReadOnly)){
        QByteArray bytes = File.readAll();
        File.close();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(bytes,&jsonError);

        if(jsonError.error != QJsonParseError::NoError){
            qDebug()<<"ERROR, in Json Data when trying to read botoneraTestCases.json";
            return;
        }

        if(document.isObject()){
            testingJsonData = document.object();
        }

    }
    else{
        qDebug()<<"ERROR, No se pudo abrir botoneraTestCases.json";
    }
}

void formatConcentratorTest::createTestTable(){
    QTest::addColumn<QString>("range");
    QTest::addColumn<QString>("displaySelection");
    QTest::addColumn<QString>("threatAssessment");
    QTest::addColumn<QString>("center");
    QTest::addColumn<QString>("displayMode");
    QTest::addColumn<QString>("qek");
    QTest::addColumn<QString>("icm");
    QTest::addColumn<QString>("overlay");
    QTest::addColumn<QString>("mik");
    QTest::addColumn<QString>("qekS");
    QTest::addColumn<QString>("centerS");
    QTest::addColumn<QString>("icmS");
    QTest::addColumn<QString>("overlayS");
    QTest::addColumn<QBitArray>("expectedResult");
}

void formatConcentratorTest::addRowToTestTable(QJsonObject testCase){
    QJsonObject parameters;
    QString id, range, displaySelection, threatAssessment,
            center, displayMode, qek, icm, overlay,
            mik, qekS, centerS, icmS, overlayS, expectedResult;

    id = testCase["id"].toString();
    parameters = testCase["parameters"].toObject();
    range = parameters["range"].toString();
    displaySelection = parameters["displaySelection"].toString();
    threatAssessment = parameters["threatAssessment"].toString();
    center = parameters["center"].toString();
    displayMode = parameters["displayMode"].toString();
    qek = parameters["qek"].toString();
    icm = parameters["icm"].toString();
    overlay = parameters["overlay"].toString();
    mik = parameters["mik"].toString();
    qekS = parameters["qekS"].toString();
    centerS = parameters["centerS"].toString();
    icmS = parameters["icmS"].toString();
    overlayS = parameters["overlayS"].toString();
    expectedResult = parameters["expectedResult"].toString();

    QTest::newRow(qPrintable(id))
        << range
        << displaySelection
        << threatAssessment
        << center
        << displayMode
        << qek
        << icm
        << overlay
        << mik
        << qekS
        << centerS
        << icmS
        << overlayS
        << BitArrayUtils::qBitArrayfromString(expectedResult);
}

StubEstado* formatConcentratorTest::fetchDataFromTestTable(){
    StubEstado* stubEstado = new StubEstado();

    QFETCH(QString, range);
    QFETCH(QString, displaySelection);
    QFETCH(QString, threatAssessment);
    QFETCH(QString, center);
    QFETCH(QString, displayMode);
    QFETCH(QString, qek);
    QFETCH(QString, icm);
    QFETCH(QString, overlay);
    QFETCH(QString, mik);
    QFETCH(QString, qekS);
    QFETCH(QString, centerS);
    QFETCH(QString, icmS);
    QFETCH(QString, overlayS);

    stubEstado->setRange(range);
    stubEstado->setDisplaySelection(displaySelection);
    stubEstado->setThreat(threatAssessment);
    stubEstado->setCenter(center);
    stubEstado->setDisplayMode(displayMode);
    stubEstado->setQEK(qek);
    stubEstado->setICM(icm);
    stubEstado->setOverlay(overlay);
    stubEstado->setMIK(mik);
    stubEstado->setQEKS(qekS);
    stubEstado->setCenterS(centerS);
    stubEstado->setICMS(icmS);
    stubEstado->setOverlayS(overlayS);

    return stubEstado;
}

void formatConcentratorTest::performComparison(StubEstado *stubEstado){
    FormatConcentrator* concentrator = new FormatConcentrator();
    bool comparisonResult;
    QBitArray* localTest;
    QFETCH(QBitArray, expectedResult);

    //localTest = concentrator->getMessage(stubEstado);
    comparisonResult = ((*localTest) == expectedResult);
    QVERIFY2(comparisonResult, qPrintable(BitArrayUtils::compareBitArrays((*localTest), expectedResult)));

    delete concentrator;
    delete stubEstado;
    delete localTest;
}

QTEST_MAIN(formatConcentratorTest)

#include "tst_formatconcentratortest.moc"
