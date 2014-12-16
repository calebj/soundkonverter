
#ifndef CODECPLUGIN_H
#define CODECPLUGIN_H

#include "backendplugin.h"
#include "conversionoptions.h"

class CodecPlugin;
class CodecWidget;
class TagData;

class CodecPluginItem : public BackendPluginItem
{
    Q_OBJECT
public:
    CodecPluginItem( QObject *parent=0 );
    virtual ~CodecPluginItem();

    struct Data {
        int length;
    } data;
};

class CodecPlugin : public BackendPlugin
{
    Q_OBJECT
public:
    CodecPlugin( QObject *parent=0 );
    virtual ~CodecPlugin();

    virtual QString type();

    virtual QList<ConversionPipeTrunk> codecTable() = 0;
    virtual CodecWidget *newCodecWidget() = 0;
    virtual CodecWidget *deleteCodecWidget( CodecWidget *codecWidget );

    /**
     * starts the conversion and returns either a conversion id or an error code:
     *
     * -1   unknown error
     * -100 plugin not configured
     */
    virtual unsigned int convert( const QUrl& inputFile, const QUrl& outputFile, const QString& inputCodec, const QString& outputCodec, ConversionOptions *_conversionOptions, TagData *tags = 0, bool replayGain = false ) = 0;
    /** returns a command for converting a file through a pipe; "" if pipes aren't supported */
    virtual QStringList convertCommand( const QUrl& inputFile, const QUrl& outputFile, const QString& inputCodec, const QString& outputCodec, ConversionOptions *_conversionOptions, TagData *tags = 0, bool replayGain = false ) = 0;

    virtual ConversionOptions *conversionOptionsFromXml( QDomElement conversionOptions, QList<QDomElement> *filterOptionsElements = 0 );

    ConversionOptions *lastUsedConversionOptions;

};

Q_DECLARE_INTERFACE(CodecPlugin, "org.soundkonverter.codecplugin")

#endif // CODECPLUGIN_H
