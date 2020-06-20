
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_F2FluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_F2FluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998v_F2FluxProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    F2  = getVariableReference( "F2" ).getVariable();
    r_act  = getVariableReference( "r_act" ).getVariable();
    F1  = getVariableReference( "F1" ).getVariable();
    r_inact  = getVariableReference( "r_inact" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( r_act->getValue()*F1->getValue()-r_inact->getValue()*F2->getValue() );
  }

 protected:

  Variable* F2;
  Variable* r_act;
  Variable* F1;
  Variable* r_inact;


};

LIBECS_DM_INIT( Nygren_1998v_F2FluxProcess, Process );
