/*  _  __  ____    _   _ 
 * | |/ / |  _ \  | \ | |
 * | ' /  | |_) | |  \| |
 * | . \  |  __/  | |\  |
 * |_|\_\ |_|     |_| \_|
 * 
 * (c) 2018 KPN
 * License: MIT License.
 * Author: Jan Bogaerts
 * 
 * support for bool sensor header
 */

#ifndef SENMLBOOLRECORD
#define SENMLBOOLRECORD

#include <senml_record_t.h>

/**
 * A SenMLRecord that stores boolean data.
 * This type of object can only be used for sensor data. If actuation is needed, use SenMLBoolActuator
 * instead.
 */ 
class SenMLBoolRecord: public SenMLRecordTemplate<bool>
{
public:
    SenMLBoolRecord();
    SenMLBoolRecord(const char* name);
    SenMLBoolRecord(const char* name, SenMLUnit unit);
    SenMLBoolRecord(const char* name, SenMLUnit unit, bool value):  SenMLRecordTemplate(name, unit, value){};
    ~SenMLBoolRecord(){};

    /**
     * renders all the fields to json, without the starting and ending brackets.
     * Inheriters can extend this function if they want to add extra fields to the json output
     * note: this is public so that custom implementations for the record object can use other objects 
     * internally and render to json using this function (ex: coordinatesRecord using 3 floatRecrods for lat, lon & alt.
     * @returns: None
    */
    virtual void fieldsToJson();

    /**
     * renders all the fields to cbor format. renders all the fields of the object without the length info 
     * at the beginning
     * note: this is public so that custom implementations for the record object can use other objects 
     * internally and render to json using this function (ex: coordinatesRecord using 3 floatRecrods for 
     * lat, lon & alt.
     * @returns: The number of bytes that were written.
    */
    virtual int fieldsToCbor();

protected:
    
private:
};

#endif // SENMLBOOLRECORD






