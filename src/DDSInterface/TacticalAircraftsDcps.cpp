//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: TacticalAircraftsDcps.cpp
//  Source: TacticalAircraftsData/TacticalAircraftsDcps.idl
//  Generated: Wed Nov 11 09:15:35 2015
//  OpenSplice V5.5.1OSS
//  
//******************************************************************

#include "TacticalAircraftsDcps.h"

#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUVLSeq < TacticalAircrafts::TacticalAircraftsData, struct TacticalAircraftsDataSeq_uniq_>;
#endif

const char * TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface::_local_id = "IDL:TacticalAircrafts/TacticalAircraftsDataTypeSupportInterface:1.0";

TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface_ptr TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface::_duplicate (TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface::_local_id) == 0)
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

TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface_ptr TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface_ptr> (p);
      result->m_count++;
   }
   return result;
}

TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface_ptr TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface_ptr result;
   result = dynamic_cast < TacticalAircrafts::TacticalAircraftsDataTypeSupportInterface_ptr> (p);
   result->m_count++;
   return result;
}

const char * TacticalAircrafts::TacticalAircraftsDataDataWriter::_local_id = "IDL:TacticalAircrafts/TacticalAircraftsDataDataWriter:1.0";

TacticalAircrafts::TacticalAircraftsDataDataWriter_ptr TacticalAircrafts::TacticalAircraftsDataDataWriter::_duplicate (TacticalAircrafts::TacticalAircraftsDataDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TacticalAircrafts::TacticalAircraftsDataDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, TacticalAircrafts::TacticalAircraftsDataDataWriter::_local_id) == 0)
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

TacticalAircrafts::TacticalAircraftsDataDataWriter_ptr TacticalAircrafts::TacticalAircraftsDataDataWriter::_narrow (DDS::Object_ptr p)
{
   TacticalAircrafts::TacticalAircraftsDataDataWriter_ptr result = NULL;
   if (p && p->_is_a (TacticalAircrafts::TacticalAircraftsDataDataWriter::_local_id))
   {
      result = dynamic_cast < TacticalAircrafts::TacticalAircraftsDataDataWriter_ptr> (p);
      result->m_count++;
   }
   return result;
}

TacticalAircrafts::TacticalAircraftsDataDataWriter_ptr TacticalAircrafts::TacticalAircraftsDataDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   TacticalAircrafts::TacticalAircraftsDataDataWriter_ptr result;
   result = dynamic_cast < TacticalAircrafts::TacticalAircraftsDataDataWriter_ptr> (p);
   result->m_count++;
   return result;
}

const char * TacticalAircrafts::TacticalAircraftsDataDataReader::_local_id = "IDL:TacticalAircrafts/TacticalAircraftsDataDataReader:1.0";

TacticalAircrafts::TacticalAircraftsDataDataReader_ptr TacticalAircrafts::TacticalAircraftsDataDataReader::_duplicate (TacticalAircrafts::TacticalAircraftsDataDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TacticalAircrafts::TacticalAircraftsDataDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, TacticalAircrafts::TacticalAircraftsDataDataReader::_local_id) == 0)
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

TacticalAircrafts::TacticalAircraftsDataDataReader_ptr TacticalAircrafts::TacticalAircraftsDataDataReader::_narrow (DDS::Object_ptr p)
{
   TacticalAircrafts::TacticalAircraftsDataDataReader_ptr result = NULL;
   if (p && p->_is_a (TacticalAircrafts::TacticalAircraftsDataDataReader::_local_id))
   {
      result = dynamic_cast < TacticalAircrafts::TacticalAircraftsDataDataReader_ptr> (p);
      result->m_count++;
   }
   return result;
}

TacticalAircrafts::TacticalAircraftsDataDataReader_ptr TacticalAircrafts::TacticalAircraftsDataDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   TacticalAircrafts::TacticalAircraftsDataDataReader_ptr result;
   result = dynamic_cast < TacticalAircrafts::TacticalAircraftsDataDataReader_ptr> (p);
   result->m_count++;
   return result;
}

const char * TacticalAircrafts::TacticalAircraftsDataDataReaderView::_local_id = "IDL:TacticalAircrafts/TacticalAircraftsDataDataReaderView:1.0";

TacticalAircrafts::TacticalAircraftsDataDataReaderView_ptr TacticalAircrafts::TacticalAircraftsDataDataReaderView::_duplicate (TacticalAircrafts::TacticalAircraftsDataDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean TacticalAircrafts::TacticalAircraftsDataDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, TacticalAircrafts::TacticalAircraftsDataDataReaderView::_local_id) == 0)
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

TacticalAircrafts::TacticalAircraftsDataDataReaderView_ptr TacticalAircrafts::TacticalAircraftsDataDataReaderView::_narrow (DDS::Object_ptr p)
{
   TacticalAircrafts::TacticalAircraftsDataDataReaderView_ptr result = NULL;
   if (p && p->_is_a (TacticalAircrafts::TacticalAircraftsDataDataReaderView::_local_id))
   {
      result = dynamic_cast < TacticalAircrafts::TacticalAircraftsDataDataReaderView_ptr> (p);
      result->m_count++;
   }
   return result;
}

TacticalAircrafts::TacticalAircraftsDataDataReaderView_ptr TacticalAircrafts::TacticalAircraftsDataDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   TacticalAircrafts::TacticalAircraftsDataDataReaderView_ptr result;
   result = dynamic_cast < TacticalAircrafts::TacticalAircraftsDataDataReaderView_ptr> (p);
   result->m_count++;
   return result;
}



