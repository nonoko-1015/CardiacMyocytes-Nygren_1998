
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998p_iAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998p_iAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );


  }

  Nygren_1998p_iAssignmentProcess()
  {
    // do nothing
  }



  virtual void initialize()
  {
    Process::initialize();

    p_i  = getVariableReference( "p_i" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    p_i->setValue( 1 * (1.00000/(1.00000+exp((V->getValue()+55.0000)/24.0000))) );

  }

 protected:

  Variable* p_i;
  Variable* V;


};

LIBECS_DM_INIT( Nygren_1998p_iAssignmentProcess, Process );
