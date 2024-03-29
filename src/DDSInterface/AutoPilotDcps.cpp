//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: AutoPilotDcps.cpp
//  Source: AutoPilotData/AutoPilotDcps.idl
//  Generated: Mon Jan  9 16:42:13 2017
//  OpenSplice V5.5.1OSS
//  
//******************************************************************

#include "AutoPilotDcps.h"

#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUFLSeq < AutoPilot::AutoPilotData, struct AutoPilotDataSeq_uniq_>;
#endif

const char * AutoPilot::AutoPilotDataTypeSupportInterface::_local_id = "IDL:AutoPilot/AutoPilotDataTypeSupportInterface:1.0";

AutoPilot::AutoPilotDataTypeSupportInterface_ptr AutoPilot::AutoPilotDataTypeSupportInterface::_duplicate (AutoPilot::AutoPilotDataTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean AutoPilot::AutoPilotDataTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, AutoPilot::AutoPilotDataTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

AutoPilot::AutoPilotDataTypeSupportInterface_ptr AutoPilot::AutoPilotDataTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   AutoPilot::AutoPilotDataTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (AutoPilot::AutoPilotDataTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < AutoPilot::AutoPilotDataTypeSupportInterface_ptr> (p);
      result->m_count++;
   }
   return result;
}

AutoPilot::AutoPilotDataTypeSupportInterface_ptr AutoPilot::AutoPilotDataTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   AutoPilot::AutoPilotDataTypeSupportInterface_ptr result;
   result = dynamic_cast < AutoPilot::AutoPilotDataTypeSupportInterface_ptr> (p);
   result->m_count++;
   return result;
}

const char * AutoPilot::AutoPilotDataDataWriter::_local_id = "IDL:AutoPilot/AutoPilotDataDataWriter:1.0";

AutoPilot::AutoPilotDataDataWriter_ptr AutoPilot::AutoPilotDataDataWriter::_duplicate (AutoPilot::AutoPilotDataDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean AutoPilot::AutoPilotDataDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, AutoPilot::AutoPilotDataDataWriter::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

AutoPilot::AutoPilotDataDataWriter_ptr AutoPilot::AutoPilotDataDataWriter::_narrow (DDS::Object_ptr p)
{
   AutoPilot::AutoPilotDataDataWriter_ptr result = NULL;
   if (p && p->_is_a (AutoPilot::AutoPilotDataDataWriter::_local_id))
   {
      result = dynamic_cast < AutoPilot::AutoPilotDataDataWriter_ptr> (p);
      result->m_count++;
   }
   return result;
}

AutoPilot::AutoPilotDataDataWriter_ptr AutoPilot::AutoPilotDataDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   AutoPilot::AutoPilotDataDataWriter_ptr result;
   result = dynamic_cast < AutoPilot::AutoPilotDataDataWriter_ptr> (p);
   result->m_count++;
   return result;
}

const char * AutoPilot::AutoPilotDataDataReader::_local_id = "IDL:AutoPilot/AutoPilotDataDataReader:1.0";

AutoPilot::AutoPilotDataDataReader_ptr AutoPilot::AutoPilotDataDataReader::_duplicate (AutoPilot::AutoPilotDataDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean AutoPilot::AutoPilotDataDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, AutoPilot::AutoPilotDataDataReader::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

AutoPilot::AutoPilotDataDataReader_ptr AutoPilot::AutoPilotDataDataReader::_narrow (DDS::Object_ptr p)
{
   AutoPilot::AutoPilotDataDataReader_ptr result = NULL;
   if (p && p->_is_a (AutoPilot::AutoPilotDataDataReader::_local_id))
   {
      result = dynamic_cast < AutoPilot::AutoPilotDataDataReader_ptr> (p);
      result->m_count++;
   }
   return result;
}

AutoPilot::AutoPilotDataDataReader_ptr AutoPilot::AutoPilotDataDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   AutoPilot::AutoPilotDataDataReader_ptr result;
   result = dynamic_cast < AutoPilot::AutoPilotDataDataReader_ptr> (p);
   result->m_count++;
   return result;
}

const char * AutoPilot::AutoPilotDataDataReaderView::_local_id = "IDL:AutoPilot/AutoPilotDataDataReaderView:1.0";

AutoPilot::AutoPilotDataDataReaderView_ptr AutoPilot::AutoPilotDataDataReaderView::_duplicate (AutoPilot::AutoPilotDataDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean AutoPilot::AutoPilotDataDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, AutoPilot::AutoPilotDataDataReaderView::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReaderView NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

AutoPilot::AutoPilotDataDataReaderView_ptr AutoPilot::AutoPilotDataDataReaderView::_narrow (DDS::Object_ptr p)
{
   AutoPilot::AutoPilotDataDataReaderView_ptr result = NULL;
   if (p && p->_is_a (AutoPilot::AutoPilotDataDataReaderView::_local_id))
   {
      result = dynamic_cast < AutoPilot::AutoPilotDataDataReaderView_ptr> (p);
      result->m_count++;
   }
   return result;
}

AutoPilot::AutoPilotDataDataReaderView_ptr AutoPilot::AutoPilotDataDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   AutoPilot::AutoPilotDataDataReaderView_ptr result;
   result = dynamic_cast < AutoPilot::AutoPilotDataDataReaderView_ptr> (p);
   result->m_count++;
   return result;
}



