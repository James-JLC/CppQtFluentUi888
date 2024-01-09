#pragma once

#include <QWidget>
#include <QLabel>
#include "FluCodeExpander.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

#include "../FluUtils/FluUtils.h"

class FluDisplayBox : public QWidget
{
    Q_OBJECT
  public:
    FluDisplayBox(QWidget* parent = nullptr);


    void paintEvent(QPaintEvent* event)
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter painter(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    }
  protected:
      QVBoxLayout* m_mainLayout;
      QLabel* m_titleLabel;
      QWidget* m_bodyWidget;
      QVBoxLayout* m_vBodyLayout;
      FluCodeExpander* m_codeExpander;

};