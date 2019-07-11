#include "AutoPilotDcps_impl.h"
#include "gapi.h"
#include "gapi_loanRegistry.h"
#include "AutoPilotSplDcps.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


extern c_bool
__AutoPilot_AutoPilotData__copyIn(
    c_base base,
    struct AutoPilot::AutoPilotData *from,
    struct _AutoPilot_AutoPilotData *to);

extern void
__AutoPilot_AutoPilotData__copyOut(
    void *_from,
    void *_to);

// DDS AutoPilot::AutoPilotData TypeSupportFactory Object Body

 DDS::DataWriter_ptr 
AutoPilot::AutoPilotDataTypeSupportFactory::create_datawriter (gapi_dataWriter handle)
{
    return new AutoPilot::AutoPilotDataDataWriter_impl(handle);
}

 DDS::DataReader_ptr 
AutoPilot::AutoPilotDataTypeSupportFactory::create_datareader (gapi_dataReader handle)
{
    return new AutoPilot::AutoPilotDataDataReader_impl (handle);
}


 DDS::DataReaderView_ptr 
AutoPilot::AutoPilotDataTypeSupportFactory::create_view (gapi_dataReaderView handle)
{
    return new AutoPilot::AutoPilotDataDataReaderView_impl (handle);
}

// DDS AutoPilot::AutoPilotData TypeSupport Object Body

 AutoPilot::AutoPilotDataTypeSupport::AutoPilotDataTypeSupport(void) :
    TypeSupport_impl(
        __AutoPilot_AutoPilotData__name(),
        __AutoPilot_AutoPilotData__keys(),
        AutoPilot::AutoPilotDataTypeSupport::metaDescriptor,
        (gapi_copyIn) __AutoPilot_AutoPilotData__copyIn,
        (gapi_copyOut) __AutoPilot_AutoPilotData__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<AutoPilot::AutoPilotDataSeq, AutoPilot::AutoPilotData>,
        new  AutoPilot::AutoPilotDataTypeSupportFactory())
{
    // Parent constructor takes care of everything.
}

 AutoPilot::AutoPilotDataTypeSupport::~AutoPilotDataTypeSupport(void)
{
    // Parent destructor takes care of everything.
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataTypeSupport::register_type(
    DDS::DomainParticipant_ptr domain,
    const char * type_name) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

 char *
AutoPilot::AutoPilotDataTypeSupport::get_type_name() THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS AutoPilot::AutoPilotData DataWriter_impl Object Body

 AutoPilot::AutoPilotDataDataWriter_impl::AutoPilotDataDataWriter_impl (
    gapi_dataWriter handle
) : DDS::DataWriter_impl(handle)
{
    // Parent constructor takes care of everything.
}

 AutoPilot::AutoPilotDataDataWriter_impl::~AutoPilotDataDataWriter_impl(void)
{
    // Parent destructor takes care of everything.
}

 DDS::InstanceHandle_t
AutoPilot::AutoPilotDataDataWriter_impl::register_instance(
    const AutoPilot::AutoPilotData & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
}

 DDS::InstanceHandle_t 
AutoPilot::AutoPilotDataDataWriter_impl::register_instance_w_timestamp(
    const AutoPilotData & instance_data,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataWriter_impl::unregister_instance(
    const AutoPilot::AutoPilotData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);
}

 DDS::ReturnCode_t 
AutoPilot::AutoPilotDataDataWriter_impl::unregister_instance_w_timestamp(
    const AutoPilotData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataWriter_impl::write(
    const AutoPilot::AutoPilotData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataWriter_impl::write_w_timestamp(
    const AutoPilotData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataWriter_impl::dispose(
    const AutoPilot::AutoPilotData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}

 DDS::ReturnCode_t 
AutoPilot::AutoPilotDataDataWriter_impl::dispose_w_timestamp(
    const AutoPilotData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataWriter_impl::writedispose(
    const AutoPilot::AutoPilotData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose(&instance_data, handle);
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataWriter_impl::writedispose_w_timestamp(
    const AutoPilotData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t 
AutoPilot::AutoPilotDataDataWriter_impl::get_key_value(
    AutoPilotData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
AutoPilot::AutoPilotDataDataWriter_impl::lookup_instance(
	const AutoPilot::AutoPilotData & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::lookup_instance(&instance_data);
}

// DDS AutoPilot::AutoPilotData DataReader_impl Object Body

 AutoPilot::AutoPilotDataDataReader_impl::AutoPilotDataDataReader_impl (
    gapi_dataReader handle
) : DDS::DataReader_impl(handle)
{
    // Parent constructor takes care of everything.
}

 AutoPilot::AutoPilotDataDataReader_impl::~AutoPilotDataDataReader_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReader_impl::read(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::take(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::read_w_condition(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::take_w_condition(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::read_next_sample(
    AutoPilot::AutoPilotData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
AutoPilot::AutoPilotDataDataReader_impl::take_next_sample(
    AutoPilot::AutoPilotData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReader_impl::read_instance(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::take_instance(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::read_next_instance(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::take_next_instance(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::read_next_instance_w_condition(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::take_next_instance_w_condition(
    AutoPilot::AutoPilotDataSeq & received_data,
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
AutoPilot::AutoPilotDataDataReader_impl::return_loan(
    AutoPilot::AutoPilotDataSeq & received_data,
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
                        AutoPilot::AutoPilotDataSeq::freebuf( received_data.get_buffer(false) );
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
AutoPilot::AutoPilotDataDataReader_impl::get_key_value(
    AutoPilot::AutoPilotData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
AutoPilot::AutoPilotDataDataReader_impl::lookup_instance(
    const AutoPilot::AutoPilotData & instance) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

 DDS::ReturnCode_t 
AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(
    AutoPilot::AutoPilotDataSeq & received_data,
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


// DDS AutoPilot::AutoPilotData DataReaderView_impl Object Body

 AutoPilot::AutoPilotDataDataReaderView_impl::AutoPilotDataDataReaderView_impl (
    gapi_dataReaderView handle
) : DDS::DataReaderView_impl(handle)
{
    // Parent constructor takes care of everything.
}

 AutoPilot::AutoPilotDataDataReaderView_impl::~AutoPilotDataDataReaderView_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReaderView_impl::read(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReaderView_impl::take(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReaderView_impl::read_w_condition(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReaderView_impl::take_w_condition(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
AutoPilot::AutoPilotDataDataReaderView_impl::read_next_sample(
    AutoPilot::AutoPilotData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
AutoPilot::AutoPilotDataDataReaderView_impl::take_next_sample(
    AutoPilot::AutoPilotData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReaderView_impl::read_instance(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReaderView_impl::take_instance(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReaderView_impl::read_next_instance(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReaderView_impl::take_next_instance(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


 DDS::ReturnCode_t 
AutoPilot::AutoPilotDataDataReaderView_impl::read_next_instance_w_condition(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
AutoPilot::AutoPilotDataDataReaderView_impl::take_next_instance_w_condition(
    AutoPilot::AutoPilotDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = AutoPilot::AutoPilotDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t
AutoPilot::AutoPilotDataDataReaderView_impl::return_loan(
    AutoPilot::AutoPilotDataSeq & received_data,
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
                        AutoPilot::AutoPilotDataSeq::freebuf( received_data.get_buffer(false) );
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
AutoPilot::AutoPilotDataDataReaderView_impl::get_key_value(
    AutoPilot::AutoPilotData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
AutoPilot::AutoPilotDataDataReaderView_impl::lookup_instance(
    const AutoPilot::AutoPilotData & instance) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::lookup_instance(&instance);
}



const char * ::AutoPilot::AutoPilotDataTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"AutoPilot\"><Struct name=\"AutoPilotData\"><Member name=\"ID\">"
"<Long/></Member><Member name=\"ThrottleCommand\"><Double/></Member><Member name=\"ElevatorCommand\"><Double/>"
"</Member><Member name=\"AileronCommand\"><Double/></Member><Member name=\"RudderCommand\"><Double/></Member>"
"<Member name=\"LeftBrakeCommand\"><Double/></Member><Member name=\"RightBrakeCommand\"><Double/></Member>"
"<Member name=\"FlapCommand\"><Double/></Member><Member name=\"EngineStartSwitch\"><Boolean/></Member>"
"<Member name=\"WindSpeedCommand\"><Double/></Member><Member name=\"WindDirectionCommand\"><Double/></Member>"
"</Struct></Module></MetaData>";
