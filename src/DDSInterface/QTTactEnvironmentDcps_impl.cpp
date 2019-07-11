#include "QTTactEnvironmentDcps_impl.h"
#include "gapi.h"
#include "gapi_loanRegistry.h"
#include "QTTactEnvironmentSplDcps.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


extern c_bool
__QTTacticalEnvironment_QTTacticalEnvironmentData__copyIn(
    c_base base,
    struct QTTacticalEnvironment::QTTacticalEnvironmentData *from,
    struct _QTTacticalEnvironment_QTTacticalEnvironmentData *to);

extern void
__QTTacticalEnvironment_QTTacticalEnvironmentData__copyOut(
    void *_from,
    void *_to);

// DDS QTTacticalEnvironment::QTTacticalEnvironmentData TypeSupportFactory Object Body

 DDS::DataWriter_ptr 
QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupportFactory::create_datawriter (gapi_dataWriter handle)
{
    return new QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl(handle);
}

 DDS::DataReader_ptr 
QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupportFactory::create_datareader (gapi_dataReader handle)
{
    return new QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl (handle);
}


 DDS::DataReaderView_ptr 
QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupportFactory::create_view (gapi_dataReaderView handle)
{
    return new QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl (handle);
}

// DDS QTTacticalEnvironment::QTTacticalEnvironmentData TypeSupport Object Body

 QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupport::QTTacticalEnvironmentDataTypeSupport(void) :
    TypeSupport_impl(
        __QTTacticalEnvironment_QTTacticalEnvironmentData__name(),
        __QTTacticalEnvironment_QTTacticalEnvironmentData__keys(),
        QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupport::metaDescriptor,
        (gapi_copyIn) __QTTacticalEnvironment_QTTacticalEnvironmentData__copyIn,
        (gapi_copyOut) __QTTacticalEnvironment_QTTacticalEnvironmentData__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<QTTacticalEnvironment::QTTacticalEnvironmentDataSeq, QTTacticalEnvironment::QTTacticalEnvironmentData>,
        new  QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupportFactory())
{
    // Parent constructor takes care of everything.
}

 QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupport::~QTTacticalEnvironmentDataTypeSupport(void)
{
    // Parent destructor takes care of everything.
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupport::register_type(
    DDS::DomainParticipant_ptr domain,
    const char * type_name) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

 char *
QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupport::get_type_name() THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS QTTacticalEnvironment::QTTacticalEnvironmentData DataWriter_impl Object Body

 QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::QTTacticalEnvironmentDataDataWriter_impl (
    gapi_dataWriter handle
) : DDS::DataWriter_impl(handle)
{
    // Parent constructor takes care of everything.
}

 QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::~QTTacticalEnvironmentDataDataWriter_impl(void)
{
    // Parent destructor takes care of everything.
}

 DDS::InstanceHandle_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::register_instance(
    const QTTacticalEnvironment::QTTacticalEnvironmentData & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
}

 DDS::InstanceHandle_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::register_instance_w_timestamp(
    const QTTacticalEnvironmentData & instance_data,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::unregister_instance(
    const QTTacticalEnvironment::QTTacticalEnvironmentData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);
}

 DDS::ReturnCode_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::unregister_instance_w_timestamp(
    const QTTacticalEnvironmentData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::write(
    const QTTacticalEnvironment::QTTacticalEnvironmentData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::write_w_timestamp(
    const QTTacticalEnvironmentData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::dispose(
    const QTTacticalEnvironment::QTTacticalEnvironmentData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}

 DDS::ReturnCode_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::dispose_w_timestamp(
    const QTTacticalEnvironmentData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::writedispose(
    const QTTacticalEnvironment::QTTacticalEnvironmentData & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose(&instance_data, handle);
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::writedispose_w_timestamp(
    const QTTacticalEnvironmentData & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::get_key_value(
    QTTacticalEnvironmentData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataWriter_impl::lookup_instance(
	const QTTacticalEnvironment::QTTacticalEnvironmentData & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::lookup_instance(&instance_data);
}

// DDS QTTacticalEnvironment::QTTacticalEnvironmentData DataReader_impl Object Body

 QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::QTTacticalEnvironmentDataDataReader_impl (
    gapi_dataReader handle
) : DDS::DataReader_impl(handle)
{
    // Parent constructor takes care of everything.
}

 QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::~QTTacticalEnvironmentDataDataReader_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::read(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::take(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::read_w_condition(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::take_w_condition(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::read_next_sample(
    QTTacticalEnvironment::QTTacticalEnvironmentData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::take_next_sample(
    QTTacticalEnvironment::QTTacticalEnvironmentData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::read_instance(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::take_instance(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::read_next_instance(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::take_next_instance(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::read_next_instance_w_condition(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::take_next_instance_w_condition(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::return_loan(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
                        QTTacticalEnvironment::QTTacticalEnvironmentDataSeq::freebuf( received_data.get_buffer(false) );
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::get_key_value(
    QTTacticalEnvironment::QTTacticalEnvironmentData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::lookup_instance(
    const QTTacticalEnvironment::QTTacticalEnvironmentData & instance) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

 DDS::ReturnCode_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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


// DDS QTTacticalEnvironment::QTTacticalEnvironmentData DataReaderView_impl Object Body

 QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::QTTacticalEnvironmentDataDataReaderView_impl (
    gapi_dataReaderView handle
) : DDS::DataReaderView_impl(handle)
{
    // Parent constructor takes care of everything.
}

 QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::~QTTacticalEnvironmentDataDataReaderView_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::read(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::take(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::read_w_condition(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::take_w_condition(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::read_next_sample(
    QTTacticalEnvironment::QTTacticalEnvironmentData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::take_next_sample(
    QTTacticalEnvironment::QTTacticalEnvironmentData & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::read_instance(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::take_instance(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::read_next_instance(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::take_next_instance(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


 DDS::ReturnCode_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::read_next_instance_w_condition(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::take_next_instance_w_condition(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = QTTacticalEnvironment::QTTacticalEnvironmentDataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::return_loan(
    QTTacticalEnvironment::QTTacticalEnvironmentDataSeq & received_data,
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
                        QTTacticalEnvironment::QTTacticalEnvironmentDataSeq::freebuf( received_data.get_buffer(false) );
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
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::get_key_value(
    QTTacticalEnvironment::QTTacticalEnvironmentData & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
QTTacticalEnvironment::QTTacticalEnvironmentDataDataReaderView_impl::lookup_instance(
    const QTTacticalEnvironment::QTTacticalEnvironmentData & instance) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::lookup_instance(&instance);
}



const char * ::QTTacticalEnvironment::QTTacticalEnvironmentDataTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"QTTacticalEnvironment\"><Struct name=\"QTTacticalEnvironmentData\">"
"<Member name=\"ID\"><Long/></Member><Member name=\"CreatAircraft\"><Array size=\"5\"><Boolean/></Array>"
"</Member><Member name=\"TEAircraftName\"><Array size=\"5\"><String/></Array></Member><Member name=\"TEAircraftVelocity\">"
"<Array size=\"5\"><Double/></Array></Member><Member name=\"TEAircraftDesiredTargetHeading\"><Array size=\"5\">"
"<Double/></Array></Member><Member name=\"TEAircraftTotalNumberOfPoints\"><Array size=\"5\"><Long/></Array>"
"</Member><Member name=\"TEAircraftRateOfClimb\"><Array size=\"5\"><Double/></Array></Member><Member name=\"TEAircraftRateOFTurn\">"
"<Array size=\"5\"><Double/></Array></Member><Member name=\"TEAircraftPathLatitude\"><Array size=\"5\">"
"<Array size=\"4\"><Double/></Array></Array></Member><Member name=\"TEAircraftPathLongitude\"><Array size=\"5\">"
"<Array size=\"4\"><Double/></Array></Array></Member><Member name=\"TEAircraftPathAltitude\"><Array size=\"5\">"
"<Array size=\"4\"><Double/></Array></Array></Member><Member name=\"TEAircraftPathHeading\"><Array size=\"5\">"
"<Array size=\"4\"><Double/></Array></Array></Member></Struct></Module></MetaData>";
