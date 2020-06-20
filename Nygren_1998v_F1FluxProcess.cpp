
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_F1FluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_F1FluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, r_recov );

  }

  Nygren_1998v_F1FluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, r_recov );


  virtual void initialize()
  {
    Process::initialize();

    F1  = getVariableReference( "F1" ).getVariable();
    F2  = getVariableReference( "F2" ).getVariable();
    r_act  = getVariableReference( "r_act" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( r_recov*((1.00000-F1->getValue())-F2->getValue())-r_act->getValue()*F1->getValue() );
  }

 protected:

  Variable* F1;
  Variable* F2;
  Variable* r_act;

  Real r_recov;

};

LIBECS_DM_INIT( Nygren_1998v_F1FluxProcess, Process );
