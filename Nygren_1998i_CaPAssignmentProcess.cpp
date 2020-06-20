
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_CaPAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_CaPAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, k_CaP );
    PROPERTYSLOT_SET_GET( Real, i_CaP_max );

  }

  Nygren_1998i_CaPAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, k_CaP );
  SIMPLE_SET_GET_METHOD( Real, i_CaP_max );


  virtual void initialize()
  {
    Process::initialize();

    i_CaP  = getVariableReference( "i_CaP" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();

  }

  virtual void fire()
  {
    i_CaP->setValue( 1 * ((i_CaP_max*(Ca_i->getMolarConc()*1000))/((Ca_i->getMolarConc()*1000)+k_CaP)) );

  }

 protected:

  Variable* i_CaP;
  Variable* Ca_i;

  Real k_CaP;
  Real i_CaP_max;

};

LIBECS_DM_INIT( Nygren_1998i_CaPAssignmentProcess, Process );
