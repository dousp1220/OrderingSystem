#include "SelectedOrderFormDelegate.h"
#include "Common.h"
#include <QSpinBox>
#include <QLineEdit>

SelectedOrderFormDelegate::SelectedOrderFormDelegate(QObject *parent)
    : QItemDelegate(parent)
{

}

QWidget *SelectedOrderFormDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    switch(index.column())
    {
    case EN_count:
    {
        QSpinBox *editor =  new  QSpinBox(parent);
        editor->setMinimum(0);
        editor->setMaximum(100);
        return  editor;
    }
    case EN_Remarks:
    {
        QLineEdit *editor = new QLineEdit(parent);
        return  editor;
    }
    default:
        return QItemDelegate::createEditor(parent, option, index);
    }
}

void SelectedOrderFormDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    switch(index.column())
    {
    case EN_count:
    {
        int  value = index.model()->data(index, Qt::EditRole).toInt();
        QSpinBox *spinBox =  static_cast <QSpinBox*>(editor);
        spinBox->setValue(value);
        break;
    }
    case EN_Remarks:
    {
        QString value = index.model()->data(index, Qt::EditRole).toString();
        QLineEdit *lineEdit =  static_cast <QLineEdit*>(editor);
        lineEdit->setText(value);
        break;
    }
    default:
    {
        QItemDelegate::setEditorData(editor, index);
    }
    }
}

void SelectedOrderFormDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    switch(index.column())
    {
    case EN_count:
    {
        QSpinBox *spinBox =  static_cast <QSpinBox*>(editor);
        spinBox->interpretText();
        int  value = spinBox->value();
        model->setData(index, value, Qt::EditRole);
        break;
    }
    case EN_Remarks:
    {
        QLineEdit *lineEdit =  static_cast <QLineEdit*>(editor);
        model->setData(index, lineEdit->text(), Qt::EditRole);
        break;
    }
    default:
    {
        QItemDelegate::setModelData(editor, model, index);
    }
    }

}
