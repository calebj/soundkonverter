
#ifndef FLACCODECWIDGET_H
#define FLACCODECWIDGET_H

#include "../../core/codecwidget.h"

class QCheckBox;
class KLineEdit;

class TTAEncCodecWidget : public CodecWidget
{
    Q_OBJECT
public:
    TTAEncCodecWidget();
    ~TTAEncCodecWidget();

    ConversionOptions *currentConversionOptions();
    bool setCurrentConversionOptions( const ConversionOptions *_options );
    void setCurrentFormat( const QString& format );
    QString currentProfile();
    bool setCurrentProfile( const QString& profile );
    int currentDataRate();

private:
    QCheckBox *cCmdArguments;
    KLineEdit *lCmdArguments;

    QString currentFormat; // holds the current output file format
};

#endif // FLACCODECWIDGET_H
