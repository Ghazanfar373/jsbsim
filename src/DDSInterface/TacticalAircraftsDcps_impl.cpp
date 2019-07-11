#include "TacticalAircraftsDcps_impl.h"
#include "gapi.h"
#include "gapi_loanRegistry.h"
#include "TacticalAircraftsSplDcps.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


extern c_bool
__TacticalAircrafts_TacticalAircraftsData__copyIn(
    c_base base,
    struct TacticalAircrafts::TacticalAircraftsData *from,
    struct _TacticalAircrafts_TacticalAircraftsData *to);

extern void
__TacticalAircrafts_TacticalAircraftsData__copyOut(
    void *_from,
    void *_to);

// DDS TacticalAircrafts::TacticalAircraftsData TypeSupportFactory Object Body

 DDS::DataWriter_ptr 
TacticalAircrafts::TacticalAircraftsDataTypeSupportFactory::create_datawriter (gapi_dataWriter handle)
{
    return new TacticalAircrafts::TacticalAircraftsDataDataWriter_impl(handle);
}

 DDS::DataReader_ptr 
TacticalAircrafts::TacticalAircraftsDataTypeSupportFactory::create_datareader (gapi_dataReader handle)
{
    return new TacticalAircrafts::TacticalAircraftsDataDataReader_impl (handle);
}


 DDS::DataReaderView_ptr 
TacticalAircrafts::TacticalAircraftsDataTypeSupportFactory::create_view (gapi_dataReaderView handle)
{
    return new TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl (handle);
}

// DDS TacticalAircrafts::TacticalAircraftsData TypeSupport Object Body

 TacticalAircrafts::TacticalAircraftsDataTypeSupport::TacticalAircraftsDataTypeSupport(void) :
    TypeSupport_impl(
        __TacticalAircrafts_TacticalAircraftsData__name(),
        __TacticalAircrafts_TacticalAircraftsData__keys(),
        TacticalAircrafts::TacticalAircraftsDataTypeSupport::metaDescriptor,
        (gapi_copyIn) __TacticalAircrafts_TacticalAircraftsData__copyIn,
        (gapi_copyOut) __TacticalAircrafts_TacticalAircraftsData__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TacticalAircrafts::TacticalAircraftsDataSeq, TacticalAircrafts::TacticalAircraftsData>,
        new  TacticalAircrafts::TacticalAircraftsDataTypeSupportFactory())
{
    // Parent constructor takes care of everything.
}

 TacticalAircrafts::TacticalAircraftsDataTypeSupport::~TacticalAircraftsDataTypeSupport(void)
{
    // Parent destructor takes care of everything.
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataTypeSupport::register_type(
    DDS::DomainParticipant_ptr domain,
    const char * type_name) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

 char *
TacticalAircrafts::TacticalAircraftsDataTypeSupport::get_type_name() THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TacticalAircrafts::TacticalAircraftsData DataWriter_impl Object Body

 TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::TacticalAircraftsDataDataWriter_impl (
    gapi_dataWriter handle
) : DDS::DataWriter_impl(handle)
{
    // Parent constructor takes care of everything.
}

 TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::~TacticalAircraftsDataDataWriter_impl(void)
{
    // Parent destructor takes care of everything.
}

 DDS::InstanceHandle_t
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::register_instance(
    const TacticalAircrafts::TacticalAircraftsData & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
}

 DDS::InstanceHandle_t 
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::register_instance_w_timestamp(
    const TacticalAircraftsData & instance_data,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::unregister_instance(
    const TacticalAircrafts::TacticalAircraftsData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);
}

 DDS::ReturnCode_t 
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::unregister_instance_w_timestamp(
    const TacticalAircraftsData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::write(
    const TacticalAircrafts::TacticalAircraftsData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::write_w_timestamp(
    const TacticalAircraftsData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::dispose(
    const TacticalAircrafts::TacticalAircraftsData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}

 DDS::ReturnCode_t 
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::dispose_w_timestamp(
    const TacticalAircraftsData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::writedispose(
    const TacticalAircrafts::TacticalAircraftsData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose(&instance_data, handle);
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::writedispose_w_timestamp(
    const TacticalAircraftsData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t 
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::get_key_value(
    TacticalAircraftsData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
TacticalAircrafts::TacticalAircraftsDataDataWriter_impl::lookup_instance(
	const TacticalAircrafts::TacticalAircraftsData & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::lookup_instance(&instance_data);
}

// DDS TacticalAircrafts::TacticalAircraftsData DataReader_impl Object Body

 TacticalAircrafts::TacticalAircraftsDataDataReader_impl::TacticalAircraftsDataDataReader_impl (
    gapi_dataReader handle
) : DDS::DataReader_impl(handle)
{
    // Parent constructor takes care of everything.
}

 TacticalAircrafts::TacticalAircraftsDataDataReader_impl::~TacticalAircraftsDataDataReader_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::read(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::take(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::read_w_condition(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::take_w_condition(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::read_next_sample(
    TacticalAircrafts::TacticalAircraftsData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::take_next_sample(
    TacticalAircrafts::TacticalAircraftsData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::read_instance(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::take_instance(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::read_next_instance(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::take_next_instance(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::read_next_instance_w_condition(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::take_next_instance_w_condition(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::return_loan(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
                        TacticalAircrafts::TacticalAircraftsDataSeq::freebuf( received_data.get_buffer(false) );
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
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::get_key_value(
    TacticalAircrafts::TacticalAircraftsData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::lookup_instance(
    const TacticalAircrafts::TacticalAircraftsData & instance) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

 DDS::ReturnCode_t 
TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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


// DDS TacticalAircrafts::TacticalAircraftsData DataReaderView_impl Object Body

 TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::TacticalAircraftsDataDataReaderView_impl (
    gapi_dataReaderView handle
) : DDS::DataReaderView_impl(handle)
{
    // Parent constructor takes care of everything.
}

 TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::~TacticalAircraftsDataDataReaderView_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::read(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::take(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::read_w_condition(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::take_w_condition(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::read_next_sample(
    TacticalAircrafts::TacticalAircraftsData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::take_next_sample(
    TacticalAircrafts::TacticalAircraftsData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::read_instance(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::take_instance(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::read_next_instance(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::take_next_instance(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


 DDS::ReturnCode_t 
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::read_next_instance_w_condition(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::take_next_instance_w_condition(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = TacticalAircrafts::TacticalAircraftsDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::return_loan(
    TacticalAircrafts::TacticalAircraftsDataSeq & received_data,
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
                        TacticalAircrafts::TacticalAircraftsDataSeq::freebuf( received_data.get_buffer(false) );
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
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::get_key_value(
    TacticalAircrafts::TacticalAircraftsData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
TacticalAircrafts::TacticalAircraftsDataDataReaderView_impl::lookup_instance(
    const TacticalAircrafts::TacticalAircraftsData & instance) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::lookup_instance(&instance);
}



const char * ::TacticalAircrafts::TacticalAircraftsDataTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TacticalAircrafts\"><Struct name=\"TacticalAircraftsData\">"
"<Member name=\"ID\"><Long/></Member><Member name=\"TEAircraftExists\"><Array size=\"5\"><Boolean/></Array>"
"</Member><Member name=\"TEAircraftName\"><Array size=\"5\"><String/></Array></Member><Member name=\"TEAircraftVelocity\">"
"<Array size=\"5\"><Double/></Array></Member><Member name=\"TEAircraftLatitude\"><Array size=\"5\"><Double/>"
"</Array></Member><Member name=\"TEAircraftLongitude\"><Array size=\"5\"><Double/></Array></Member><Member name=\"TEAircraftAltitude\">"
"<Array size=\"5\"><Double/></Array></Member><Member name=\"TEAircraftHeading\"><Array size=\"5\"><Double/>"
"</Array></Member><Member name=\"TEAircraftPitchAngle\"><Array size=\"5\"><Double/></Array></Member><Member name=\"TEAircraftRollAngle\">"
"<Array size=\"5\"><Double/></Array></Member><Member name=\"TEAircraftRateOfClimb\"><Array size=\"5\">"
"<Double/></Array></Member><Member name=\"TEAircraftOnCollissionCourse\"><Array size=\"5\"><Boolean/></Array>"
"</Member><Member name=\"TEAircraftTimeToCollision\"><Array size=\"5\"><Double/></Array></Member></Struct>"
"</Module></MetaData>";
