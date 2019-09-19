#ifndef GECI_H
#define GECI_H

#include <QFrame>

namespace Ui {
class Geci;
}

class Geci : public QFrame
{
    Q_OBJECT

public:
    explicit Geci(QWidget *parent = 0);
    ~Geci();

private:
    Ui::Geci *ui;
};

#endif // GECI_H
