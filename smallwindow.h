#ifndef SMALLWINDOW_H
#define SMALLWINDOW_H

#include <QWidget>

namespace Ui {
class SmallWindow;
}

class SmallWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWindow(QWidget *parent = 0);
    ~SmallWindow();
    Ui::SmallWindow *ui;

private:

public slots:
    void changeBig(void);
signals:
    void back(void);
};

#endif // SMALLWINDOW_H
