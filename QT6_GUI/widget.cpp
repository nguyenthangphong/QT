#include "widget.h"
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget{parent}
{
    QFont labelFont("Times", 10, QFont::Bold);
    QLabel *mLabel = new QLabel("This is my text", this);
    mLabel->setFont(labelFont);
    mLabel->move(100, 25);

    QTextEdit *textEdit = new QTextEdit(this);
    textEdit->move(70, 55);

    // textChanged
    connect(textEdit, &QTextEdit::textChanged, [=](){
        qDebug() << "Text Changed";
    });

    // Copy
    QPushButton *copyButton = new QPushButton("Copy", this);
    copyButton->setMinimumSize(50, 25);
    copyButton->move(10, 250);

    connect(copyButton, &QPushButton::clicked, [=](){
        textEdit->copy();
    });

    // Cut
    QPushButton *cutButton = new QPushButton("Cut", this);
    cutButton->setMinimumSize(50, 25);
    cutButton->move(110, 250);

    connect(cutButton, &QPushButton::clicked, [=](){
        textEdit->cut();
    });

    // Paste
    QPushButton *pasteButton = new QPushButton("Paste", this);
    pasteButton->setMinimumSize(50, 25);
    pasteButton->move(210, 250);

    connect(pasteButton, &QPushButton::clicked, [=](){
        textEdit->paste();
    });

    // Undo
    QPushButton *undoButton = new QPushButton("Undo", this);
    undoButton->setMinimumSize(50, 25);
    undoButton->move(10, 280);

    connect(undoButton, &QPushButton::clicked, [=](){
        textEdit->undo();
    });


    // Redo
    QPushButton *redoButton = new QPushButton("Redo", this);
    redoButton->setMinimumSize(50, 25);
    redoButton->move(110, 280);

    connect(redoButton, &QPushButton::clicked, [=](){
        textEdit->redo();
    });

    // Plain Text
    QPushButton *plainTextButton = new QPushButton("Plain Text", this);
    plainTextButton->setMinimumSize(100, 25);
    plainTextButton->move(10, 310);

    connect(plainTextButton, &QPushButton::clicked, [=](){
        textEdit->setPlainText("Sed ut perspiciatis unde omnis iste natus");
    });

    // Html
    QPushButton *htmlButton = new QPushButton("Html", this);
    htmlButton->setMinimumSize(100, 25);
    htmlButton->move(120, 310);

    connect(htmlButton, &QPushButton::clicked, [=](){
        textEdit->setHtml("<h1>Kigali Districts</h1>The city of Kigali");
    });

    // Grab Text
    QPushButton *grabTextButton = new QPushButton("Grab Text", this);
    grabTextButton->setMinimumSize(100, 25);
    grabTextButton->move(10, 340);

    connect(grabTextButton, &QPushButton::clicked, [=](){
        qDebug() << "The plain text inside the text edit is : " << textEdit->toPlainText();
    });

    // Grab Html
    QPushButton *grabHtmlButton = new QPushButton("Grab Html", this);
    grabHtmlButton->setMinimumSize(100, 25);
    grabHtmlButton->move(120, 340);

    connect(grabHtmlButton, &QPushButton::clicked, [=](){
        qDebug() << "The html inside the text edit is : " << textEdit->toHtml();
    });
}

Widget::~Widget()
{

}
