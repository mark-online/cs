// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

/**
 * @file
 * @brief Generated from character_title_table.xsd.
 */

#ifndef GDT_CHARACTER_TITLE_TABLE_HXX
#define GDT_CHARACTER_TITLE_TABLE_HXX

#ifndef XSD_CXX11
#define XSD_CXX11
#endif

#ifndef XSD_USE_WCHAR
#define XSD_USE_WCHAR
#endif

#ifndef XSD_CXX_TREE_USE_WCHAR
#define XSD_CXX_TREE_USE_WCHAR
#endif

// Begin prologue.
//
#include "shared_types.hxx"
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include "xml_schema.hxx"

// Forward declarations.
//
namespace gdt
{
  class character_title_t;
  class character_title_table;
}


#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#ifndef XSD_DONT_INCLUDE_INLINE
#define XSD_DONT_INCLUDE_INLINE

#include "shared_types.hxx"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "shared_types.hxx"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %
 * schema namespace.
 */
namespace gdt
{
  /**
   * @brief Class corresponding to the %character_title_t schema type.
   *
   * @nosubgrouping
   */
  class GIDEON_CS_API character_title_t: public ::xml_schema::type
  {
    public:
    /**
     * @name character_title_code
     *
     * @brief Accessor and modifier functions for the %character_title_code
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::gdt::character_title_code_t character_title_code_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< character_title_code_type, wchar_t > character_title_code_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const character_title_code_type&
    character_title_code () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    character_title_code_type&
    character_title_code ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    character_title_code (const character_title_code_type& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    character_title_code (::std::unique_ptr< character_title_code_type > p);

    //@}

    /**
     * @name title
     *
     * @brief Accessor and modifier functions for the %title
     * required attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::string title_type;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< title_type, wchar_t > title_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const title_type&
    title () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    title_type&
    title ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    title (const title_type& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    title (::std::unique_ptr< title_type > p);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Default constructor.
     *
     * Note that this constructor leaves required elements and
     * attributes uninitialized.
     */
    character_title_t ();

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    character_title_t (const character_title_code_type&,
                       const title_type&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    character_title_t (const ::xercesc::DOMElement& e,
                       ::xml_schema::flags f = 0,
                       ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    character_title_t (const character_title_t& x,
                       ::xml_schema::flags f = 0,
                       ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual character_title_t*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    /**
     * @brief Copy assignment operator.
     *
     * @param x An instance to make a copy of.
     * @return A reference to itself.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    character_title_t&
    operator= (const character_title_t& x);

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~character_title_t ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< wchar_t >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< character_title_code_type > character_title_code_;
    ::xsd::cxx::tree::one< title_type > title_;

    //@endcond
  };

  /**
   * @brief Class corresponding to the %character_title_table schema type.
   *
   * @nosubgrouping
   */
  class GIDEON_CS_API character_title_table: public ::xml_schema::type
  {
    public:
    /**
     * @name character_title_template
     *
     * @brief Accessor and modifier functions for the %character_title_template
     * sequence element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::gdt::character_title_t character_title_template_type;

    /**
     * @brief Element sequence container type.
     */
    typedef ::xsd::cxx::tree::sequence< character_title_template_type > character_title_template_sequence;

    /**
     * @brief Element iterator type.
     */
    typedef character_title_template_sequence::iterator character_title_template_iterator;

    /**
     * @brief Element constant iterator type.
     */
    typedef character_title_template_sequence::const_iterator character_title_template_const_iterator;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< character_title_template_type, wchar_t > character_title_template_traits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * sequence.
     *
     * @return A constant reference to the sequence container.
     */
    const character_title_template_sequence&
    character_title_template () const;

    /**
     * @brief Return a read-write reference to the element sequence.
     *
     * @return A reference to the sequence container.
     */
    character_title_template_sequence&
    character_title_template ();

    /**
     * @brief Copy elements from a given sequence.
     *
     * @param s A sequence to copy elements from.
     *
     * For each element in @a s this function makes a copy and adds it 
     * to the sequence. Note that this operation completely changes the 
     * sequence and all old elements will be lost.
     */
    void
    character_title_template (const character_title_template_sequence& s);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    character_title_table ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    character_title_table (const ::xercesc::DOMElement& e,
                           ::xml_schema::flags f = 0,
                           ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    character_title_table (const character_title_table& x,
                           ::xml_schema::flags f = 0,
                           ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual character_title_table*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    /**
     * @brief Copy assignment operator.
     *
     * @param x An instance to make a copy of.
     * @return A reference to itself.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    character_title_table&
    operator= (const character_title_table& x);

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~character_title_table ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< wchar_t >&,
           ::xml_schema::flags);

    protected:
    character_title_template_sequence character_title_template_;

    //@endcond
  };
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "shared_types.ixx"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace gdt
{
  /**
   * @name Parsing functions for the %character_title_table document root.
   */
  //@{

  /**
   * @brief Parse a URI or a local file.
   *
   * @param uri A URI or a local file name.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (const ::std::wstring& uri,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a URI or a local file with an error handler.
   *
   * @param uri A URI or a local file name.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (const ::std::wstring& uri,
                          ::xml_schema::error_handler& eh,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a URI or a local file with a Xerces-C++ DOM error
   * handler.
   *
   * @param uri A URI or a local file name.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (const ::std::wstring& uri,
                          ::xercesc::DOMErrorHandler& eh,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream.
   *
   * @param is A standrad input stream.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::std::istream& is,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with an error handler.
   *
   * @param is A standrad input stream.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::std::istream& is,
                          ::xml_schema::error_handler& eh,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a Xerces-C++ DOM error
   * handler.
   *
   * @param is A standrad input stream.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::std::istream& is,
                          ::xercesc::DOMErrorHandler& eh,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::std::istream& is,
                          const ::std::wstring& id,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id and an
   * error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::std::istream& is,
                          const ::std::wstring& id,
                          ::xml_schema::error_handler& eh,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a standard input stream with a resource id and a
   * Xerces-C++ DOM error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::std::istream& is,
                          const ::std::wstring& id,
                          ::xercesc::DOMErrorHandler& eh,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source.
   *
   * @param is A Xerces-C++ input source.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::xercesc::InputSource& is,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source with an error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::xercesc::InputSource& is,
                          ::xml_schema::error_handler& eh,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ input source with a Xerces-C++ DOM
   * error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::xercesc::InputSource& is,
                          ::xercesc::DOMErrorHandler& eh,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (const ::xercesc::DOMDocument& d,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A pointer to the Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function is normally used together with the keep_dom and
   * own_dom parsing flags to assign ownership of the DOM document
   * to the object model.
   */
  GIDEON_CS_API
  ::std::unique_ptr< ::gdt::character_title_table >
  character_title_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
                          ::xml_schema::flags f = 0,
                          const ::xml_schema::properties& p = ::xml_schema::properties ());

  //@}
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace gdt
{
  /**
   * @name Serialization functions for the %character_title_table document root.
   */
  //@{

  /**
   * @brief Serialize to a standard output stream.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  GIDEON_CS_API
  void
  character_title_table_ (::std::ostream& os,
                          const ::gdt::character_title_table& x, 
                          const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                          const ::std::wstring& e = L"UTF-8",
                          ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a standard output stream with an error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  character_title_table_ (::std::ostream& os,
                          const ::gdt::character_title_table& x, 
                          ::xml_schema::error_handler& eh,
                          const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                          const ::std::wstring& e = L"UTF-8",
                          ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a standard output stream with a Xerces-C++ DOM
   * error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  character_title_table_ (::std::ostream& os,
                          const ::gdt::character_title_table& x, 
                          ::xercesc::DOMErrorHandler& eh,
                          const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                          const ::std::wstring& e = L"UTF-8",
                          ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  GIDEON_CS_API
  void
  character_title_table_ (::xercesc::XMLFormatTarget& ft,
                          const ::gdt::character_title_table& x, 
                          const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                          const ::std::wstring& e = L"UTF-8",
                          ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with an error
   * handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  character_title_table_ (::xercesc::XMLFormatTarget& ft,
                          const ::gdt::character_title_table& x, 
                          ::xml_schema::error_handler& eh,
                          const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                          const ::std::wstring& e = L"UTF-8",
                          ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with a
   * Xerces-C++ DOM error handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  GIDEON_CS_API
  void
  character_title_table_ (::xercesc::XMLFormatTarget& ft,
                          const ::gdt::character_title_table& x, 
                          ::xercesc::DOMErrorHandler& eh,
                          const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                          const ::std::wstring& e = L"UTF-8",
                          ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to an existing Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param x An object model to serialize.
   * @param f Serialization flags.
   *
   * Note that it is your responsibility to create the DOM document
   * with the correct root element as well as set the necessary
   * namespace mapping attributes.
   */
  GIDEON_CS_API
  void
  character_title_table_ (::xercesc::DOMDocument& d,
                          const ::gdt::character_title_table& x,
                          ::xml_schema::flags f = 0);

  /**
   * @brief Serialize to a new Xerces-C++ DOM document.
   *
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param f Serialization flags.
   * @return A pointer to the new Xerces-C++ DOM document.
   */
  GIDEON_CS_API
  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  character_title_table_ (const ::gdt::character_title_table& x, 
                          const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                          ::xml_schema::flags f = 0);

  //@}

  GIDEON_CS_API
  void
  operator<< (::xercesc::DOMElement&, const character_title_t&);

  GIDEON_CS_API
  void
  operator<< (::xercesc::DOMElement&, const character_title_table&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "character_title_table.ixx"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_CHARACTER_TITLE_TABLE_HXX
