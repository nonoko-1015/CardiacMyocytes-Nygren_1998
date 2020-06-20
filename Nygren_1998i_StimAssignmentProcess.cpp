
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_StimAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_StimAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, stim_start );
    PROPERTYSLOT_SET_GET( Real, stim_end );
    PROPERTYSLOT_SET_GET( Real, stim_amplitude );
    PROPERTYSLOT_SET_GET( Real, stim_period );
    PROPERTYSLOT_SET_GET( Real, stim_duration );

  }

  Nygren_1998i_StimAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, stim_start );
  SIMPLE_SET_GET_METHOD( Real, stim_end );
  SIMPLE_SET_GET_METHOD( Real, stim_amplitude );
  SIMPLE_SET_GET_METHOD( Real, stim_period );
  SIMPLE_SET_GET_METHOD( Real, stim_duration );


  virtual void initialize()
  {
    Process::initialize();

    i_Stim  = getVariableReference( "i_Stim" ).getVariable();
    voi  = getVariableReference( "voi" ).getVariable();

  }

  virtual void fire()
  {
    if (( voi->getValue() >= stim_start) &&
        ( voi->getValue() <= stim_end) &&
        ((voi->getValue()-stim_start)-floor((voi->getValue()-stim_start)/stim_period)*stim_period <= stim_duration)
    ) {
      i_Stim->setValue( stim_amplitude );
    } else {
      i_Stim->setValue( 0.00000 );
    }

  }

 protected:

  Variable* i_Stim;
  Variable* voi;

  Real stim_start;
  Real stim_end;
  Real stim_amplitude;
  Real stim_period;
  Real stim_duration;

};

LIBECS_DM_INIT( Nygren_1998i_StimAssignmentProcess, Process );
