#ifndef CSV_TOOLS_REPORTTABLE_H
#define CSV_TOOLS_REPORTTABLE_H

#include <QWidget>

#include <experimental/filesystem>

class QPushButton;
class QListWidget;



namespace CSMDoc
{
    class Document;
    class DocumentManager;
}

namespace CSVDoc
{
    class FileWidget;
    class AdjusterWidget;
}

namespace CSVTools
{
    class Merge : public QWidget
    {
            Q_OBJECT

            CSMDoc::Document *mDocument;
            QPushButton *mOkay;
            QListWidget *mFiles;
            CSVDoc::FileWidget *mNewFile;
            CSVDoc::AdjusterWidget *mAdjuster;
            CSMDoc::DocumentManager& mDocumentManager;

            void keyPressEvent (QKeyEvent *event);

        public:

            Merge (CSMDoc::DocumentManager& documentManager, QWidget *parent = 0);

            /// Configure dialogue for a new merge
            void configure (CSMDoc::Document *document);

            void setLocalData (const std::experimental::filesystem::path& localData);

            CSMDoc::Document *getDocument() const;

        public slots:

            void cancel();

        private slots:

            void accept();

            void stateChanged (bool valid);
    };
}

#endif
