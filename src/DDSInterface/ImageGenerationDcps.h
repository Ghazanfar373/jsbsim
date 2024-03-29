//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: ImageGenerationDcps.h
//  Source: ImageGenerationData/ImageGenerationDcps.idl
//  Generated: Tue Feb 28 15:04:54 2017
//  OpenSplice V5.5.1OSS
//  
//******************************************************************
#ifndef _IMAGEGENERATIONDCPS_H_
#define _IMAGEGENERATIONDCPS_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"
#include "dds_dcps_interfaces.h"
#include "ImageGeneration.h"
#include "dds_builtinTopics.h"
#include "dds_dcps_builtintopics.h"

namespace ImageGeneration
{
   struct ImageGenerationData;

   class ImageGenerationDataTypeSupportInterface;

   typedef ImageGenerationDataTypeSupportInterface * ImageGenerationDataTypeSupportInterface_ptr;
   typedef DDS_DCPSInterface_var < ImageGenerationDataTypeSupportInterface> ImageGenerationDataTypeSupportInterface_var;
   typedef DDS_DCPSInterface_out < ImageGenerationDataTypeSupportInterface> ImageGenerationDataTypeSupportInterface_out;


   class ImageGenerationDataDataWriter;

   typedef ImageGenerationDataDataWriter * ImageGenerationDataDataWriter_ptr;
   typedef DDS_DCPSInterface_var < ImageGenerationDataDataWriter> ImageGenerationDataDataWriter_var;
   typedef DDS_DCPSInterface_out < ImageGenerationDataDataWriter> ImageGenerationDataDataWriter_out;


   class ImageGenerationDataDataReader;

   typedef ImageGenerationDataDataReader * ImageGenerationDataDataReader_ptr;
   typedef DDS_DCPSInterface_var < ImageGenerationDataDataReader> ImageGenerationDataDataReader_var;
   typedef DDS_DCPSInterface_out < ImageGenerationDataDataReader> ImageGenerationDataDataReader_out;


   class ImageGenerationDataDataReaderView;

   typedef ImageGenerationDataDataReaderView * ImageGenerationDataDataReaderView_ptr;
   typedef DDS_DCPSInterface_var < ImageGenerationDataDataReaderView> ImageGenerationDataDataReaderView_var;
   typedef DDS_DCPSInterface_out < ImageGenerationDataDataReaderView> ImageGenerationDataDataReaderView_out;

   struct ImageGenerationDataSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq < ImageGenerationData, struct ImageGenerationDataSeq_uniq_> ImageGenerationDataSeq;
   typedef DDS_DCPSSequence_var < ImageGenerationDataSeq> ImageGenerationDataSeq_var;
   typedef DDS_DCPSSequence_out < ImageGenerationDataSeq> ImageGenerationDataSeq_out;
   class ImageGenerationDataTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      typedef ImageGenerationDataTypeSupportInterface_ptr _ptr_type;
      typedef ImageGenerationDataTypeSupportInterface_var _var_type;

      static ImageGenerationDataTypeSupportInterface_ptr _duplicate (ImageGenerationDataTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static ImageGenerationDataTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static ImageGenerationDataTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static ImageGenerationDataTypeSupportInterface_ptr _nil () { return 0; }
      static const char * _local_id;
      ImageGenerationDataTypeSupportInterface_ptr _this () { return this; }


   protected:
      ImageGenerationDataTypeSupportInterface () {};
      ~ImageGenerationDataTypeSupportInterface () {};
   private:
      ImageGenerationDataTypeSupportInterface (const ImageGenerationDataTypeSupportInterface &);
      ImageGenerationDataTypeSupportInterface & operator = (const ImageGenerationDataTypeSupportInterface &);
   };

   class ImageGenerationDataDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      typedef ImageGenerationDataDataWriter_ptr _ptr_type;
      typedef ImageGenerationDataDataWriter_var _var_type;

      static ImageGenerationDataDataWriter_ptr _duplicate (ImageGenerationDataDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static ImageGenerationDataDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static ImageGenerationDataDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static ImageGenerationDataDataWriter_ptr _nil () { return 0; }
      static const char * _local_id;
      ImageGenerationDataDataWriter_ptr _this () { return this; }

      virtual DDS::InstanceHandle_t register_instance (const ImageGenerationData& instance_data) = 0;
      virtual DDS::InstanceHandle_t register_instance_w_timestamp (const ImageGenerationData& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t unregister_instance (const ImageGenerationData& instance_data, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::ReturnCode_t unregister_instance_w_timestamp (const ImageGenerationData& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t write (const ImageGenerationData& instance_data, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::ReturnCode_t write_w_timestamp (const ImageGenerationData& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t dispose (const ImageGenerationData& instance_data, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::ReturnCode_t dispose_w_timestamp (const ImageGenerationData& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t writedispose (const ImageGenerationData& instance_data, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::ReturnCode_t writedispose_w_timestamp (const ImageGenerationData& instance_data, DDS::InstanceHandle_t handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::ReturnCode_t get_key_value (ImageGenerationData& key_holder, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::InstanceHandle_t lookup_instance (const ImageGenerationData& instance_data) = 0;

   protected:
      ImageGenerationDataDataWriter () {};
      ~ImageGenerationDataDataWriter () {};
   private:
      ImageGenerationDataDataWriter (const ImageGenerationDataDataWriter &);
      ImageGenerationDataDataWriter & operator = (const ImageGenerationDataDataWriter &);
   };

   class ImageGenerationDataDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      typedef ImageGenerationDataDataReader_ptr _ptr_type;
      typedef ImageGenerationDataDataReader_var _var_type;

      static ImageGenerationDataDataReader_ptr _duplicate (ImageGenerationDataDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static ImageGenerationDataDataReader_ptr _narrow (DDS::Object_ptr obj);
      static ImageGenerationDataDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static ImageGenerationDataDataReader_ptr _nil () { return 0; }
      static const char * _local_id;
      ImageGenerationDataDataReader_ptr _this () { return this; }

      virtual DDS::ReturnCode_t read (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_w_condition (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t take_w_condition (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t read_next_sample (ImageGenerationData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::ReturnCode_t take_next_sample (ImageGenerationData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::ReturnCode_t read_instance (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take_instance (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_next_instance (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take_next_instance (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_next_instance_w_condition (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t take_next_instance_w_condition (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t return_loan (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::ReturnCode_t get_key_value (ImageGenerationData& key_holder, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::InstanceHandle_t lookup_instance (const ImageGenerationData& instance) = 0;

   protected:
      ImageGenerationDataDataReader () {};
      ~ImageGenerationDataDataReader () {};
   private:
      ImageGenerationDataDataReader (const ImageGenerationDataDataReader &);
      ImageGenerationDataDataReader & operator = (const ImageGenerationDataDataReader &);
   };

   class ImageGenerationDataDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      typedef ImageGenerationDataDataReaderView_ptr _ptr_type;
      typedef ImageGenerationDataDataReaderView_var _var_type;

      static ImageGenerationDataDataReaderView_ptr _duplicate (ImageGenerationDataDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static ImageGenerationDataDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static ImageGenerationDataDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static ImageGenerationDataDataReaderView_ptr _nil () { return 0; }
      static const char * _local_id;
      ImageGenerationDataDataReaderView_ptr _this () { return this; }

      virtual DDS::ReturnCode_t read (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_w_condition (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t take_w_condition (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t read_next_sample (ImageGenerationData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::ReturnCode_t take_next_sample (ImageGenerationData& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::ReturnCode_t read_instance (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take_instance (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_next_instance (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t take_next_instance (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::SampleStateMask sample_states, DDS::ViewStateMask view_states, DDS::InstanceStateMask instance_states) = 0;
      virtual DDS::ReturnCode_t read_next_instance_w_condition (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t take_next_instance_w_condition (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::InstanceHandle_t a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::ReturnCode_t return_loan (ImageGenerationDataSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::ReturnCode_t get_key_value (ImageGenerationData& key_holder, DDS::InstanceHandle_t handle) = 0;
      virtual DDS::InstanceHandle_t lookup_instance (const ImageGenerationData& instance) = 0;

   protected:
      ImageGenerationDataDataReaderView () {};
      ~ImageGenerationDataDataReaderView () {};
   private:
      ImageGenerationDataDataReaderView (const ImageGenerationDataDataReaderView &);
      ImageGenerationDataDataReaderView & operator = (const ImageGenerationDataDataReaderView &);
   };

}
template <>
DDS::BuiltinTopicKey_t_slice* DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::copy (DDS::BuiltinTopicKey_t_slice *to, const DDS::BuiltinTopicKey_t_slice* from);
template <>
void DDS_DCPS_ArrayHelper < DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::free (DDS::BuiltinTopicKey_t_slice *ptr);




#endif 
