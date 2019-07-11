//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: TacticalAircraftsDcps.h
//  Source: TacticalAircraftsData/TacticalAircraftsDcps.idl
//  Generated: Wed Nov 11 09:15:35 2015
//  OpenSplice V5.5.1OSS
//  
//******************************************************************
#ifndef _TACTICALAIRCRAFTSDCPS_H_
#define _TACTICALAIRCRAFTSDCPS_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"
#include "dds_dcps_interfaces.h"
#include "dds_builtinTopics.h"
#include "dds_dcps_builtintopics.h"
#include "TacticalAircrafts.h"

namespace TacticalAircrafts
{
   struct TacticalAircraftsData;

   class TacticalAircraftsDataTypeSupportInterface;

   typedef TacticalAircraftsDataTypeSupportInterface * TacticalAircraftsDataTypeSupportInterface_ptr;
   typedef DDS_DCPSInterface_var < TacticalAircraftsDataTypeSupportInterface> TacticalAircraftsDataTypeSupportInterface_var;
   typedef DDS_DCPSInterface_out < TacticalAircraftsDataTypeSupportInterface> TacticalAircraftsDataTypeSupportInterface_out;


   class TacticalAircraftsDataDataWriter;

   typedef TacticalAircraftsDataDataWriter * TacticalAircraftsDataDataWriter_ptr;
   typedef DDS_DCPSInterface_var < TacticalAircraftsDataDataWriter> TacticalAircraftsDataDataWriter_var;
   typedef DDS_DCPSInterface_out < TacticalAircraftsDataDataWriter> TacticalAircraftsDataDataWriter_out;


   class TacticalAircraftsDataDataReader;

   typedef TacticalAircraftsDataDataReader * TacticalAircraftsDataDataReader_ptr;
   typedef DDS_DCPSInterface_var < TacticalAircraftsDataDataReader> TacticalAircraftsDataDataReader_var;
   typedef DDS_DCPSInterface_out < TacticalAircraftsDataDataReader> TacticalAircraftsDataDataReader_out;


   class TacticalAircraftsDataDataReaderView;

   typedef TacticalAircraftsDataDataReaderView * TacticalAircraftsDataDataReaderView_ptr;
   typedef DDS_DCPSInterface_var < TacticalAircraftsDataDataReaderView> TacticalAircraftsDataDataReaderView_var;
   typedef DDS_DCPSInterface_out < TacticalAircraftsDataDataReaderView> TacticalAircraftsDataDataReaderView_out;

   struct TacticalAircraftsDataSeq_uniq_ {};
   typedef DDS_DCPSUVLSeq < TacticalAircraftsData, struct TacticalAircraftsDataSeq_uniq_> TacticalAircraftsDataSeq;
   typedef DDS_DCPSSequence_var < TacticalAircraftsDataSeq> TacticalAircraftsDataSeq_var;
   typedef DDS_DCPSSequence_out < TacticalAircraftsDataSeq> TacticalAircraftsDataSeq_out;
   class TacticalAircraftsDataTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      typedef TacticalAircraftsDataTypeSupportInterface_ptr _ptr_type;
      typedef TacticalAircraftsDataTypeSupportInterface_var _var_type;

      static TacticalAircraftsDataTypeSupportInterface_ptr _duplicate (TacticalAircraftsDataTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static TacticalAircraftsDataTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static TacticalAircraftsDataTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static TacticalAircraftsDataTypeSupportInterface_ptr _nil () { return 0; }
      static const char * _local_id;
      TacticalAircraftsDataTypeSupportInterface_ptr _this () { return this; }


   protected:
      TacticalAircraftsDataTypeSupportInterface () {};
      ~TacticalAircraftsDataTypeSupportInterface () {};
   private:
      TacticalAircraftsDataTypeSupportInterface (const TacticalAircraftsDataTypeSupportInterface &);
      TacticalAircraftsDataTypeSupportInterface & operator = (const TacticalAircraftsDataTypeSupportInterface &);
   };

   class TacticalAircraftsDataDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      typedef TacticalAircraftsDataDataWriter_ptr _ptr_type;
      typedef TacticalAircraftsDataDataWriter_var _var_type;

      static TacticalAircraftsDataDataWriter_ptr _duplicate (TacticalAircraftsDataDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static TacticalAircraftsDataDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static TacticalAircraftsDataDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static TacticalAircraftsDataDataWriter_ptr _nil () { return 0; }
      static const char * _local_id;
      TacticalAircraftsDataDataWriter_ptr _this () { return this; }

      virtual DDS::InstanceHandle_t register_instance (const TacticalAircraftsData& instance_data) = 0;
      virtual DDS::InstanceHandle_t register_instance_w_timestamp (const TacticalAircraftsData& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t unregister_instance (const TacticalAircraftsData& instance_data, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::ReturnCode_t unregister_instance_w_timestamp (const TacticalAircraftsData& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t write (const TacticalAircraftsData& instance_data, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::ReturnCode_t write_w_timestamp (const TacticalAircraftsData& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t dispose (const TacticalAircraftsData& instance_data, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::ReturnCode_t dispose_w_timestamp (const TacticalAircraftsData& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t writedispose (const TacticalAircraftsData& instance_data, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::ReturnCode_t writedispose_w_timestamp (const TacticalAircraftsData& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t get_key_value (TacticalAircraftsData& key_holder, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::InstanceHandle_t lookup_instance (const TacticalAircraftsData& instance_data) = 0;

   protected:
      TacticalAircraftsDataDataWriter () {};
      ~TacticalAircraftsDataDataWriter () {};
   private:
      TacticalAircraftsDataDataWriter (const TacticalAircraftsDataDataWriter &);
      TacticalAircraftsDataDataWriter & operator = (const TacticalAircraftsDataDataWriter &);
   };

   class TacticalAircraftsDataDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      typedef TacticalAircraftsDataDataReader_ptr _ptr_type;
      typedef TacticalAircraftsDataDataReader_var _var_type;

      static TacticalAircraftsDataDataReader_ptr _duplicate (TacticalAircraftsDataDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static TacticalAircraftsDataDataReader_ptr _narrow (DDS::Object_ptr obj);
      static TacticalAircraftsDataDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static TacticalAircraftsDataDataReader_ptr _nil () { return 0; }
      static const char * _local_id;
      TacticalAircraftsDataDataReader_ptr _this () { return this; }

      virtual DDS::ReturnCode_t read (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_w_condition (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t take_w_condition (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t read_next_sample (TacticalAircraftsData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::ReturnCode_t take_next_sample (TacticalAircraftsData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::ReturnCode_t read_instance (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take_instance (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_next_instance (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take_next_instance (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_next_instance_w_condition (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t take_next_instance_w_condition (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t return_loan (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::ReturnCode_t get_key_value (TacticalAircraftsData& key_holder, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::InstanceHandle_t lookup_instance (const TacticalAircraftsData& instance) = 0;

   protected:
      TacticalAircraftsDataDataReader () {};
      ~TacticalAircraftsDataDataReader () {};
   private:
      TacticalAircraftsDataDataReader (const TacticalAircraftsDataDataReader &);
      TacticalAircraftsDataDataReader & operator = (const TacticalAircraftsDataDataReader &);
   };

   class TacticalAircraftsDataDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      typedef TacticalAircraftsDataDataReaderView_ptr _ptr_type;
      typedef TacticalAircraftsDataDataReaderView_var _var_type;

      static TacticalAircraftsDataDataReaderView_ptr _duplicate (TacticalAircraftsDataDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static TacticalAircraftsDataDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static TacticalAircraftsDataDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static TacticalAircraftsDataDataReaderView_ptr _nil () { return 0; }
      static const char * _local_id;
      TacticalAircraftsDataDataReaderView_ptr _this () { return this; }

      virtual DDS::ReturnCode_t read (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_w_condition (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t take_w_condition (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t read_next_sample (TacticalAircraftsData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::ReturnCode_t take_next_sample (TacticalAircraftsData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::ReturnCode_t read_instance (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take_instance (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_next_instance (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take_next_instance (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_next_instance_w_condition (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t take_next_instance_w_condition (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t return_loan (TacticalAircraftsDataSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::ReturnCode_t get_key_value (TacticalAircraftsData& key_holder, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::InstanceHandle_t lookup_instance (const TacticalAircraftsData& instance) = 0;

   protected:
      TacticalAircraftsDataDataReaderView () {};
      ~TacticalAircraftsDataDataReaderView () {};
   private:
      TacticalAircraftsDataDataReaderView (const TacticalAircraftsDataDataReaderView &);
      TacticalAircraftsDataDataReaderView & operator = (const TacticalAircraftsDataDataReaderView &);
   };

}
template <>
DDS::BuiltinTopicKey_t_slice* DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::copy (DDS::BuiltinTopicKey_t_slice *to, const DDS::BuiltinTopicKey_t_slice* from);
template <>
void DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::free (DDS::BuiltinTopicKey_t_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftExists_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftName_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftVelocity_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftLatitude_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftLongitude_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftAltitude_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftHeading_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftPitchAngle_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftRollAngle_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftRateOfClimb_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftOnCollissionCourse_array_slice *ptr);
template <>
TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_slice* DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_uniq_>::copy (TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_slice *to, const TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_slice* from);
template <>
void DDS_DCPS_ArrayHelper < TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array, TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_slice, TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_uniq_>::free (TacticalAircrafts::TacticalAircraftsData::_TEAircraftTimeToCollision_array_slice *ptr);




#endif 