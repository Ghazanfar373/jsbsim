#include "ImageGenerationDcps_impl.h"
#include "gapi.h"
#include "gapi_loanRegistry.h"
#include "ImageGenerationSplDcps.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


extern c_bool
__ImageGeneration_ImageGenerationData__copyIn(
    c_base base,
    struct ImageGeneration::ImageGenerationData *from,
    struct _ImageGeneration_ImageGenerationData *to);

extern void
__ImageGeneration_ImageGenerationData__copyOut(
    void *_from,
    void *_to);

// DDS ImageGeneration::ImageGenerationData TypeSupportFactory Object Body

 DDS::DataWriter_ptr 
ImageGeneration::ImageGenerationDataTypeSupportFactory::create_datawriter (gapi_dataWriter handle)
{
    return new ImageGeneration::ImageGenerationDataDataWriter_impl(handle);
}

 DDS::DataReader_ptr 
ImageGeneration::ImageGenerationDataTypeSupportFactory::create_datareader (gapi_dataReader handle)
{
    return new ImageGeneration::ImageGenerationDataDataReader_impl (handle);
}


 DDS::DataReaderView_ptr 
ImageGeneration::ImageGenerationDataTypeSupportFactory::create_view (gapi_dataReaderView handle)
{
    return new ImageGeneration::ImageGenerationDataDataReaderView_impl (handle);
}

// DDS ImageGeneration::ImageGenerationData TypeSupport Object Body

 ImageGeneration::ImageGenerationDataTypeSupport::ImageGenerationDataTypeSupport(void) :
    TypeSupport_impl(
        __ImageGeneration_ImageGenerationData__name(),
        __ImageGeneration_ImageGenerationData__keys(),
        ImageGeneration::ImageGenerationDataTypeSupport::metaDescriptor,
        (gapi_copyIn) __ImageGeneration_ImageGenerationData__copyIn,
        (gapi_copyOut) __ImageGeneration_ImageGenerationData__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<ImageGeneration::ImageGenerationDataSeq, ImageGeneration::ImageGenerationData>,
        new  ImageGeneration::ImageGenerationDataTypeSupportFactory())
{
    // Parent constructor takes care of everything.
}

 ImageGeneration::ImageGenerationDataTypeSupport::~ImageGenerationDataTypeSupport(void)
{
    // Parent destructor takes care of everything.
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataTypeSupport::register_type(
    DDS::DomainParticipant_ptr domain,
    const char * type_name) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

 char *
ImageGeneration::ImageGenerationDataTypeSupport::get_type_name() THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS ImageGeneration::ImageGenerationData DataWriter_impl Object Body

 ImageGeneration::ImageGenerationDataDataWriter_impl::ImageGenerationDataDataWriter_impl (
    gapi_dataWriter handle
) : DDS::DataWriter_impl(handle)
{
    // Parent constructor takes care of everything.
}

 ImageGeneration::ImageGenerationDataDataWriter_impl::~ImageGenerationDataDataWriter_impl(void)
{
    // Parent destructor takes care of everything.
}

 DDS::InstanceHandle_t
ImageGeneration::ImageGenerationDataDataWriter_impl::register_instance(
    const ImageGeneration::ImageGenerationData & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
}

 DDS::InstanceHandle_t 
ImageGeneration::ImageGenerationDataDataWriter_impl::register_instance_w_timestamp(
    const ImageGenerationData & instance_data,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataWriter_impl::unregister_instance(
    const ImageGeneration::ImageGenerationData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);
}

 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataWriter_impl::unregister_instance_w_timestamp(
    const ImageGenerationData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataWriter_impl::write(
    const ImageGeneration::ImageGenerationData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataWriter_impl::write_w_timestamp(
    const ImageGenerationData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataWriter_impl::dispose(
    const ImageGeneration::ImageGenerationData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}

 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataWriter_impl::dispose_w_timestamp(
    const ImageGenerationData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataWriter_impl::writedispose(
    const ImageGeneration::ImageGenerationData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose(&instance_data, handle);
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataWriter_impl::writedispose_w_timestamp(
    const ImageGenerationData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataWriter_impl::get_key_value(
    ImageGenerationData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
ImageGeneration::ImageGenerationDataDataWriter_impl::lookup_instance(
	const ImageGeneration::ImageGenerationData & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::lookup_instance(&instance_data);
}

// DDS ImageGeneration::ImageGenerationData DataReader_impl Object Body

 ImageGeneration::ImageGenerationDataDataReader_impl::ImageGenerationDataDataReader_impl (
    gapi_dataReader handle
) : DDS::DataReader_impl(handle)
{
    // Parent constructor takes care of everything.
}

 ImageGeneration::ImageGenerationDataDataReader_impl::~ImageGenerationDataDataReader_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReader_impl::read(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReader_impl::take(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReader_impl::read_w_condition(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReader_impl::take_w_condition(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReader_impl::read_next_sample(
    ImageGeneration::ImageGenerationData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReader_impl::take_next_sample(
    ImageGeneration::ImageGenerationData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReader_impl::read_instance(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReader_impl::take_instance(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReader_impl::read_next_instance(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReader_impl::take_next_instance(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReader_impl::read_next_instance_w_condition(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReader_impl::take_next_instance_w_condition(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReader_impl::return_loan(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 ) {
        if (received_data.length() == info_seq.length() && 
            received_data.release() == info_seq.release() ) {
            if (!received_data.release()) {
                status = DataReader_impl::return_loan( received_data.get_buffer(),
                                                       info_seq.get_buffer() );

                if ( status == DDS::RETCODE_OK ) {
                    if ( !received_data.release() ) {
                        ImageGeneration::ImageGenerationDataSeq::freebuf( received_data.get_buffer(false) );
                        received_data.replace(0, 0, NULL, false);
                        DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                        info_seq.replace(0, 0, NULL, false);
                    }
                } else if ( status == DDS::RETCODE_NO_DATA ) {
                    if ( received_data.release() ) {
                        status = DDS::RETCODE_OK;
                    } else {
                        status = DDS::RETCODE_PRECONDITION_NOT_MET;
                    }
                }
            }
        } else {
            status = DDS::RETCODE_PRECONDITION_NOT_MET;
        }
    }
    return status;
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReader_impl::get_key_value(
    ImageGeneration::ImageGenerationData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
ImageGeneration::ImageGenerationDataDataReader_impl::lookup_instance(
    const ImageGeneration::ImageGenerationData & instance) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples)
{
    DDS::ReturnCode_t status = DDS::RETCODE_PRECONDITION_NOT_MET;
    
    if ( received_data.length() == info_seq.length() &&
         received_data.maximum() == info_seq.maximum() &&
         received_data.release() == info_seq.release() ) {
        if ( received_data.maximum() == 0 || received_data.release() ) {
            if (received_data.maximum() == 0 ||
				max_samples <= static_cast<CORBA::Long>(received_data.maximum()) ||
				max_samples == DDS::LENGTH_UNLIMITED ) {
                status = DDS::RETCODE_OK;
            }
        }
    }
    return status;
}


// DDS ImageGeneration::ImageGenerationData DataReaderView_impl Object Body

 ImageGeneration::ImageGenerationDataDataReaderView_impl::ImageGenerationDataDataReaderView_impl (
    gapi_dataReaderView handle
) : DDS::DataReaderView_impl(handle)
{
    // Parent constructor takes care of everything.
}

 ImageGeneration::ImageGenerationDataDataReaderView_impl::~ImageGenerationDataDataReaderView_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReaderView_impl::read(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReaderView_impl::take(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReaderView_impl::read_w_condition(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReaderView_impl::take_w_condition(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReaderView_impl::read_next_sample(
    ImageGeneration::ImageGenerationData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReaderView_impl::take_next_sample(
    ImageGeneration::ImageGenerationData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReaderView_impl::read_instance(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReaderView_impl::take_instance(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReaderView_impl::read_next_instance(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReaderView_impl::take_next_instance(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReaderView_impl::read_next_instance_w_condition(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReaderView_impl::take_next_instance_w_condition(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = ImageGeneration::ImageGenerationDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t
ImageGeneration::ImageGenerationDataDataReaderView_impl::return_loan(
    ImageGeneration::ImageGenerationDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 ) {
        if (received_data.length() == info_seq.length() && 
            received_data.release() == info_seq.release() ) {
            if (!received_data.release()) {
                status = DataReaderView_impl::return_loan( received_data.get_buffer(),
                                                       info_seq.get_buffer() );

                if ( status == DDS::RETCODE_OK ) {
                    if ( !received_data.release() ) {
                        ImageGeneration::ImageGenerationDataSeq::freebuf( received_data.get_buffer(false) );
                        received_data.replace(0, 0, NULL, false);
                        DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                        info_seq.replace(0, 0, NULL, false);
                    }
                } else if ( status == DDS::RETCODE_NO_DATA ) {
                    if ( received_data.release() ) {
                        status = DDS::RETCODE_OK;
                    } else {
                        status = DDS::RETCODE_PRECONDITION_NOT_MET;
                    }
                }
            }
        } else {
            status = DDS::RETCODE_PRECONDITION_NOT_MET;
        }
    }
    return status;
}


 DDS::ReturnCode_t 
ImageGeneration::ImageGenerationDataDataReaderView_impl::get_key_value(
    ImageGeneration::ImageGenerationData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
ImageGeneration::ImageGenerationDataDataReaderView_impl::lookup_instance(
    const ImageGeneration::ImageGenerationData & instance) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::lookup_instance(&instance);
}



const char * ::ImageGeneration::ImageGenerationDataTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"ImageGeneration\"><Struct name=\"ImageGenerationData\"><Member name=\"ID\">"
"<Long/></Member><Member name=\"Roll_deg\"><Double/></Member><Member name=\"Pitch_deg\"><Double/></Member>"
"<Member name=\"Heading_deg\"><Double/></Member><Member name=\"Altitude_ft\"><Double/></Member><Member name=\"Latitude\">"
"<Double/></Member><Member name=\"Longitude\"><Double/></Member><Member name=\"AltitudeAboveSeaLevel_ft\">"
"<Double/></Member><Member name=\"SimTime\"><Double/></Member></Struct></Module></MetaData>";
